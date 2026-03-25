#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"
using namespace std;

class clsListUsersScreen : protected clsScreen
{
private:
    static void PrintUserRecordLine(clsUser User)
    {
        cout << setw(8) << left << "" << "| " << left << setw(12) << User.UserName;
        cout << "| " << setw(25) << left << User.FullName();
        cout << "| " << setw(12) << left << User.Phone;
        cout << "| " << setw(20) << left << User.Email;
        cout << "| " << setw(10) << left << User.Password;
        cout << "| " << setw(12) << left << User.Permissions;
    }

public:
    static void ShowListUsers()
    {
        vector <clsUser> vUsers = clsUser::GetUsersList();
        string Title = "\t  User List Screen";
        string Subtitle = "\t    (" + to_string(vUsers.size()) + ") Users ";

        clsListUsersScreen::_DrawScreenHeader(Title, Subtitle);

        cout << "\n\t_______________________________________________________";
        cout << "________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(12) << "User Name";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << "\n\t_______________________________________________________";
        cout << "________________________________________________\n" << endl;

        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else
            for (clsUser& User : vUsers)
            {
                PrintUserRecordLine(User);
                cout << endl;
            }

        cout << "\n\t_______________________________________________________";
        cout << "________________________________________________\n" << endl;
    }
};

