#pragma once
#include <iostream>
#include <string>
#include "clsScreen.h"
#include "clsUser.h"

class clsShowLoginRegisterScreen : protected clsScreen
{
private:
    static void PrintRegisterRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord)
    {
        cout << setw(8) << left << "" << "| " << left << setw(35) << LoginRegisterRecord.DateAndTime;
        cout << "| " << setw(25) << left << LoginRegisterRecord.UserName;
        cout << "| " << setw(24) << left << LoginRegisterRecord.Password;
        cout << "| " << setw(12) << left << LoginRegisterRecord.Permissions;
    }

public:
	static void ShowLoginRegisterScreen()
	{
        if (!_CheckAccessRights(clsUser::enPermissions::pRegisterLogin))
        {
            return;
        }

        vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();
        string Title = "\t  Register Login List Screen";
        string Subtitle = "\t    (" + to_string(vLoginRegisterRecord.size()) + ") Login Registers ";

		_DrawScreenHeader(Title,Subtitle);

        cout << "\n\t_______________________________________________________";
        cout << "________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(25) << "User Name";
        cout << "| " << left << setw(24) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << "\n\t_______________________________________________________";
        cout << "________________________________________________\n" << endl;

        if (vLoginRegisterRecord.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else
            for (clsUser::stLoginRegisterRecord& LoginRegister : vLoginRegisterRecord)
            {
                PrintRegisterRecordLine(LoginRegister);
                cout << endl;
            }

        cout << "\n\t_______________________________________________________";
        cout << "________________________________________________\n" << endl;

	}
};

