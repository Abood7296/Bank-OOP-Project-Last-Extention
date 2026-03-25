#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include <iomanip>

class clsBankClient1 : public clsPerson
{
private:
    enum enMode { EmptyMode = 0, UpdateMode = 1 ,AddNewMode = 2 };

    enMode _Mode;
    string _AccountNumber;
    float _AccountBalance;
    string _PinCode;
    bool MarkedForDelete = false;

    static clsBankClient1 _ConvertLineToClientObject(string Line, string Separator = "#//#")
    {
        vector<string> vClientData;

        vClientData = clsString::Split(Line, Separator);

        return clsBankClient1(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

    }

    static string _ConvertClientObjectToLine(clsBankClient1 Client, string Separator = "#//#")
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

    struct stTransferRegisterRecord;
    static stTransferRegisterRecord _ConvertTransferRegisterLineToRecord(string Line, string Separator = "#//#")
    {
        stTransferRegisterRecord TransferRegisterRecord;

        vector<string> LoginRegisterDataLine;
        LoginRegisterDataLine = clsString::Split(Line, Separator);
        TransferRegisterRecord.DateAndTime = LoginRegisterDataLine[0];
        TransferRegisterRecord.SourceAccountNumber = LoginRegisterDataLine[1];
        TransferRegisterRecord.DestinationAccountNumber = LoginRegisterDataLine[2];
        TransferRegisterRecord.Amount = stoi(LoginRegisterDataLine[3]);
        TransferRegisterRecord.SourceAccountBalance = stoi(LoginRegisterDataLine[4]);
        TransferRegisterRecord.DestinationAccountBalance = stoi(LoginRegisterDataLine[5]);
        TransferRegisterRecord.UserName = LoginRegisterDataLine[6];

        return TransferRegisterRecord;
    }

    static vector <clsBankClient1> _LoadClientsDataFromFile()
    {
        vector <clsBankClient1> vClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;

            while (getline(MyFile, Line))
            {

                clsBankClient1 Client = _ConvertLineToClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();

        }

        return vClients;
    }

    static vector <clsBankClient1> _SaveClientsDataToFile(string FileName, vector <clsBankClient1> vClients)
    {

        fstream MyFile;
        MyFile.open(FileName, ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankClient1 C : vClients)
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
        vector <clsBankClient1> _vClients = _LoadClientsDataFromFile();

        for (clsBankClient1& C : _vClients)
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

    static clsBankClient1 _GetEmptyClientObject()
    {
        return clsBankClient1(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    string _PrepareTransferLogRecord(clsBankClient1 DestinationClient,double Amount,string UserName,string Separator = "#//#")
    {
        string TransferLoginRecord = "";
        TransferLoginRecord += clsDate::GetSystemDateString() + clsDate::GetSystemTimeString() + Separator;
        TransferLoginRecord += AccountNumber() + Separator;
        TransferLoginRecord += DestinationClient.AccountNumber() + Separator;
        TransferLoginRecord += to_string(Amount) + Separator;
        TransferLoginRecord += to_string(AccountBalance) + Separator;
        TransferLoginRecord += to_string(DestinationClient.AccountBalance) + Separator;
        TransferLoginRecord += UserName;

        return TransferLoginRecord;
    }

 public:

    clsBankClient1(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance)
        : clsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _AccountBalance = AccountBalance;
        _PinCode = PinCode;
    }

    struct stTransferRegisterRecord
    {
        string DateAndTime = "";
        string SourceAccountNumber = "";
        string DestinationAccountNumber = "";
		float Amount = 0;
        float SourceAccountBalance = 0;
        float DestinationAccountBalance = 0;
        string UserName = "";
    };

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }

    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }

    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

    string AccountNumber()
    {
        return _AccountNumber;
    }

    static clsBankClient1 Find(string AccountNumber)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient1 Client = _ConvertLineToClientObject(Line);
                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }
        return _GetEmptyClientObject();
    }

    static clsBankClient1 Find(string AccountNumber, string PinCode)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient1 Client = _ConvertLineToClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }
            }

            MyFile.close();
        }
        return _GetEmptyClientObject();
    }

    bool MarkForDelete()
    {
        return MarkedForDelete;
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1 ,svFailedAcountNumberExists = 2 };

    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            return enSaveResults::svFaildEmptyObject;
        }
        case enMode::UpdateMode:
        {
            _Update();

            return enSaveResults::svSucceeded;

            break;
        }
        case enMode::AddNewMode:
        {
            //This will add new record to file or data base
            if (clsBankClient1::IsClientExist(_AccountNumber))
            {
                return enSaveResults::svFailedAcountNumberExists;
            }
            else
            {
                _AddNew();
                //We Need to set the mode to update after add new
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }
        }
        }
    }

    static bool IsClientExist(string AccountNumber)
    {
        clsBankClient1 Client1 = clsBankClient1::Find(AccountNumber);
        return (!Client1.IsEmpty());
    }

    static clsBankClient1 GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient1(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

    bool Delete()
    {
        vector <clsBankClient1> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient1& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C.MarkedForDelete = true;
                break;
            }
        }
        _SaveClientsDataToFile("Clients.txt", _vClients);

        *this = _GetEmptyClientObject();
        return true;
    }

    static vector <clsBankClient1> GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }

    static double GetTotalBalances()
    {
        vector <clsBankClient1> vClients = _LoadClientsDataFromFile();

        double TotalBalances = 0;

        for (clsBankClient1& C : vClients)
        {
            TotalBalances += C.AccountBalance;
        }

        return TotalBalances;
    }

    void Deposit(double Amount)
    {
       _AccountBalance += Amount;
       Save();
    }

    bool Withdraw(double Amount)
    {
        if (_AccountBalance < Amount)
        {
            cout << "\nCannot withdraw Insufficient Balance!.\n";
            cout << "Account Balance :" << this->AccountBalance << endl;
            return false;
        }
        else
        {
            _AccountBalance -= Amount;
            Save();
            return true;
        }
    }

    bool Transfer(float Amount, clsBankClient1& DestinationClient,string UserName)
    {
        if (Amount > AccountBalance)
        {
            return false;
        }

        Withdraw(Amount);
        DestinationClient.Deposit(Amount);
        RegisterTransferLog(DestinationClient, Amount, UserName);
        return true;
    }

    static vector <stTransferRegisterRecord> GetTransferRegisterList()
    {
        vector <stTransferRegisterRecord> vTransferLogRecord;

        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;

            stTransferRegisterRecord TransferRecord;

            while (getline(MyFile, Line))
            {
                TransferRecord = _ConvertTransferRegisterLineToRecord(Line);

                vTransferLogRecord.push_back(TransferRecord);
            }
            MyFile.close();
        }
        return vTransferLogRecord;
    }

    void RegisterTransferLog(clsBankClient1 DestinationClient,double Amount,string UserName)
    {
        string stDataLine = _PrepareTransferLogRecord(DestinationClient, Amount, UserName);
        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::out | ios::app);
        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;

            MyFile.close();
		}
    }

    // NO UI Related Code Inside Object.
    //void Print()
    //{
    //    cout << "\nClient Card:";
    //    cout << "\n___________________";
    //    cout << "\nFirstName   : " << FirstName;
    //    cout << "\nLastName    : " << LastName;
    //    cout << "\nFull Name   : " << FullName();
    //    cout << "\nEmail       : " << Email;
    //    cout << "\nPhone       : " << Phone;
    //    cout << "\nAcc. Number : " << _AccountNumber;
    //    cout << "\nPassword    : " << _PinCode;
    //    cout << "\nBalance     : " << _AccountBalance;
    //    cout << "\n___________________\n";
    //}
};