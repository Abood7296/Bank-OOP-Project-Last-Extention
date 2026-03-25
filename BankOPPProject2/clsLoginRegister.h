#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsString.h"
using namespace std;


class clsLoginRegister
{
private:
	string _UserName;
	string _Password;
	string _DateAndTime;
    int _Permissions;

    static clsLoginRegister _ConvertLineToUserObject(string Line, string Separator = "#//#")
    {
        vector<string> vUserData;
        vUserData = clsString::Split(Line, Separator);

        return clsLoginRegister(vUserData[4], vUserData[5], stoi(vUserData[6]));

    }

    static string _ConvertUserObjectToLine(clsLoginRegister LoginRegister, string Separator = "#//#")
    {
        std::string UserRecord = "";
        UserRecord += LoginRegister._DateAndTime + Separator;
        UserRecord += LoginRegister._UserName + Separator;
        UserRecord += LoginRegister._Password + Separator;
        UserRecord += std::to_string(LoginRegister._Permissions);

        return UserRecord;

    }

    static void _SaveUsersDataToFile(vector <clsLoginRegister> vUsers)
    {
        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsLoginRegister U : vUsers)
            {
                DataLine = _ConvertUserObjectToLine(U);
                MyFile << DataLine << endl;
            }
            MyFile.close();
        }

    }

public:
    clsLoginRegister(string UserName, string Password, int Permissions)
    {
        _UserName = UserName;
        _Password = Password;
        _DateAndTime = 
        _Permissions = Permissions;
    }

    static clsLoginRegister Find(string UserName, string Password)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsLoginRegister User = _ConvertLineToUserObject(Line);
                if (User._UserName == UserName && User._Password == Password)
                {
                    MyFile.close();
                    return User;
                }
            }
            MyFile.close();
        }
        return _GetEmptyUserObject();
    }

    static clsLoginRegister _GetEmptyUserObject()
    {
        return clsLoginRegister( "", "", 0);
    }

    static void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static void WriteRecordInLoginRegister(string UserName,string Password)
    {
        clsLoginRegister LR = clsLoginRegister::Find(UserName, Password);
        _AddDataLineToFile(_ConvertUserObjectToLine(LR));
    }



};

