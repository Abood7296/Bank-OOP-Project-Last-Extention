#pragma once
#include <iostream>
#include <string>
#include "clsBankClient1.h"
#include "clsScreen.h"
using namespace std;

class clsFindClientScreen : protected clsScreen
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

public :
	static void ShowFindClientScreen()
	{
        if (!_CheckAccessRights(clsUser::enPermissions::pFindClient))
        {
            return;
        }

        _DrawScreenHeader("\t Find Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient1::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient1 Client1 = clsBankClient1::Find(AccountNumber);

        if (!Client1.IsEmpty())
        {
            cout << "\nClient Found :-)\n";
        }   
        else
        {
            cout << "\nClient Was not Found :-(\n";
        }

        _PrintClient(Client1);
	}
};

