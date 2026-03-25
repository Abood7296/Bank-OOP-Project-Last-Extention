#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include <iomanip>

class clsBankUser
{
private:
    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };

    enMode _Mode;
    string _UserName = "";
    string _Password = "";
    int _Permissions = 0;
    bool _MarkForDelete = false;

    static clsBankUser _ConvertLineToUserObject(string Line, string Separator = "#//#")
    {
        vector<string> vUsersData;

        vUsersData = clsString::Split(Line, Separator);

        return clsBankUser(enMode::UpdateMode, vUsersData[0], vUsersData[1]);
    }

    static string _ConvertClientObjectToLine(clsBankUser User, string Separator = "#//#")
    {

        string stClientRecord = "";
        stClientRecord += Client.FirstName + Separator;
        stClientRecord += Client.LastName + Separator;
        stClientRecord += Client.Email + Separator;
        stClientRecord += Client.Phone + Separator;
        stClientRecord += Client.AccountNumber() + Separator;
        stClientRecord += Client.PinCode + Separator;
        stClientRecord += to_string(Client.AccountBalance);

        return stClientRecord;
    }

    static vector <clsBankUser> _LoadClientsDataFromFile()
    {
        vector <clsBankUser> vClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;

            while (getline(MyFile, Line))
            {

                clsBankUser Client = _ConvertLineToClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();

        }

        return vClients;
    }

    static vector <clsBankUser> _SaveClientsDataToFile(string FileName, vector <clsBankUser> vClients)
    {

        fstream MyFile;
        MyFile.open(FileName, ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankUser C : vClients)
            {
                if (C.MarkForDelete() == false)
                {
                    //we only write records that are not marked for delete.
                    DataLine = _ConvertClientObjectToLine(C);
                    MyFile << DataLine << endl;
                }
            }

            MyFile.close();

        }

        return vClients;
    }

    void _Update()
    {
        vector <clsBankUser> _vClients = _LoadClientsDataFromFile();

        for (clsBankUser& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }
        }
        _SaveClientsDataToFile("Clients.txt", _vClients);
    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConvertClientObjectToLine(*this));
    }

    static clsBankUser _GetEmptyClientObject()
    {
        return clsBankUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    void _AddDataLineToFile(string stDataLine)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    public:
        clsBankUser(enMode Mode, string UserName,string Password)
        {
            _Mode = Mode;
            _UserName = UserName;
            _Password = Password;
        }


};

