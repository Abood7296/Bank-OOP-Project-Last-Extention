#pragma once
#include <iostream>
#include <string>
#include "clsBankClient1.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

class clsUpdateClientScreen : protected clsScreen
{
private :
    static void _PrintClient(clsBankClient1 Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";
    }

    static void _ReadClientInfo(clsBankClient1& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();
    }

public :
    static void UpdateClientScreen()
    {
        if (!_CheckAccessRights(clsUser::enPermissions::pUpdateClient))
        {
            return;
        }

        _DrawScreenHeader("\t Update Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter Client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient1::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient1 Client1 = clsBankClient1::Find(AccountNumber);
        _PrintClient(Client1);

        cout << "\n\nUpdate Client Info:";
        cout << "\n____________________\n";

        _ReadClientInfo(Client1);

        clsBankClient1::enSaveResults SaveResult;

        SaveResult = Client1.Save();

        switch (SaveResult)
        {
        case  clsBankClient1::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Updated Successfully :-)\n";
            _PrintClient(Client1);
            break;
        }
        case clsBankClient1::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError Account was not saved because it's Empty";
            break;
        }
        }
    }
};

