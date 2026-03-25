#pragma once
#include <iostream>
#include <string>
#include "clsBankClient1.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
using namespace std;

class clsAddNewClientScreen : protected clsScreen
{
private :
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
    static void ShowAddNewClientScreen()
    {
        if (!_CheckAccessRights(clsUser::enPermissions::pAddNewClient))
        {
            return;
        }

        clsAddNewClientScreen::_DrawScreenHeader("\t  Add New Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient1::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number in Use, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient1 NewClient = clsBankClient1::GetAddNewClientObject(AccountNumber);

        _ReadClientInfo(NewClient);

        clsBankClient1::enSaveResults SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case clsBankClient1::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Added Successfully :-)\n";
            _PrintClient(NewClient);
            break;
        }
        case clsBankClient1::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError Account was not saved because it's Empty";
            break;
        }
        case clsBankClient1::svFailedAcountNumberExists:
        {
            cout << "\nFailed,Because Account Number in Use";
            break;
        }
        }


    }

};

