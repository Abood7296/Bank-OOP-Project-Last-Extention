#pragma once
#include <iostream>
#include <string>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsLoginRegister.h"
#include "Global.h"
class clsLoginScreen : protected clsScreen
{
private :
	static void Counter(short Attempts,short UsedAttempts = 3)
	{
		if (Attempts == UsedAttempts)
		{
			cout << "\nYou have used all attempts, try again later.\n";
			exit(0);
		}
	}
public:

	static void ShowLoginScreen()
	{
		_DrawScreenHeader("\t Login User Screen");

	    short Counter = 3;
		cout << "\nPlease Enter User Name: ";
		string UserName = clsInputValidate::ReadString();
		cout << "\nPlease Enter Password: ";
		string Password = clsInputValidate::ReadString();

		while (!clsUser::IsCorrectPassword(UserName,Password))
		{
			if (Counter == 1)
			{
				cout << "\nYou Are Locked After 3 Failed Trials.\n";
				CurrentUser = clsUser::Find("", "");
				return;
			}
			Counter--;
			cout << "\nUser Name and Password isn't Correct, Entered Again: ";
			cout << "\nYou Have " << Counter <<" Trials To Login.\n";
			cout << "\nEnter User Name: ";
			UserName = clsInputValidate::ReadString();
			cout << "\nEnter Password: ";
			Password = clsInputValidate::ReadString();
		}

		CurrentUser = clsUser::Find(UserName,Password);
		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenu();
	}
		//clsLoginRegister::WriteRecordInLoginRegister(UserName, Password);
};

