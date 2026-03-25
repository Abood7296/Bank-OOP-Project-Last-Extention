#pragma once
#include <iostream>
#include <string>
#include "clsBankClient1.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

class clsDeleteClientScreen : protected clsScreen
{
private:
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

public:
    static void ShowDeleteClientScreen()
    {
        if (!_CheckAccessRights(clsUser::enPermissions::pDeleteClient))
        {
            return;
        }

        _DrawScreenHeader("\t  Delete Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient1::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient1 Client1 = clsBankClient1::Find(AccountNumber);
        _PrintClient(Client1);
        cout << "\nAre you Sure You want to delete this Client y/n\n";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            if (Client1.Delete())
            {
                cout << "\nClient Deleted Successfully :-)\n";
                _PrintClient(Client1);
            }
            else
                cout << "\nError Client Was Not Deleted\n";

        }

    }

};

