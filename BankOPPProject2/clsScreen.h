#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"
#include "clsUser.h"
#include "Global.h"
using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n";

        clsDate SystemDate = clsDate::GetSystemDate();
        cout << "\n\t\t\t\t\tUser : " << CurrentUser.UserName;
        cout << "\n\t\t\t\t\tDate : "; SystemDate.Print();
        cout << endl;
    }

    static bool _CheckAccessRights(clsUser::enPermissions Permission)
    {
        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t________________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact Your Admin";
            cout << "\n\t\t\t\t\t________________________________________\n";
            return false;
        }
        else
            return true;
    }
};

