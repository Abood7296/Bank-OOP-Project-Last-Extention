#pragma once
#include <iostream>
#include <string>
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
using namespace std;

class clsAddNewUserScreen : protected clsScreen
{
private:
    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        User.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\nEnter Password: ";
        User.Password = clsInputValidate::ReadString();

        cout << "\nEnter Permissions: ";
        User.Permissions = _ReadPermissionsToSet();
    }

    static void _PrintUser(clsUser User)
    {
        cout << "\User Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\Permissions  : " << User.Permissions;
        cout << "\n___________________\n";
    }

    static int _ReadPermissionsToSet()
    {
        int Permissions = 0;
        char Answer = 'n';

        cout << "\nDo you want to give Full Access? y/n\n";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions = clsUser::enPermissions::eAll;
        }

        cout << "\nDo you want to give Access to :\n";
        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::plistClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClient;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTransactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }

		cout << "\nShow Login Register? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pRegisterLogin;
		}

        return Permissions;
    }

public:
    static void ShowAddNewUserScreen()
    {
        _DrawScreenHeader("\t  Add New User Screen");

        string UserName = "";

        cout << "\nPlease Enter User Name : ";
        UserName = clsInputValidate::ReadString();

        while (clsUser::IsUserExist(UserName))
        {
            cout << "\nUser Name in Use, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

        _ReadUserInfo(NewUser);

        clsUser::enSaveResults SaveResult;

        SaveResult = NewUser.Save();

        switch (SaveResult)
        {
        case clsUser::enSaveResults::svSucceeded:
        {
            cout << "\User Added Successfully :-)\n";
            _PrintUser(NewUser);
            break;
        }
        case clsUser::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError User was not saved because it's Empty";
            break;
        }
        case clsUser::svFaildUserExists:
        {
            cout << "\nFailed,Because User Name in Use";
            break;
        }
        }


    }
};

