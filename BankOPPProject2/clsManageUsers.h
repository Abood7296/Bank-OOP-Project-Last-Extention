#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

using namespace std;

class clsManageUsers : protected clsScreen
{
	enum enManageUsersMenuOptions
	{
		ListUsers = 1, AddNewUser = 2, DeleteUser = 3, UpdateUser = 4, FindUser = 5, MainMenu = 6
	};

	static int _ReadManageUsersMenuOptions()
	{
		cout << setw(37) << left << "\t\t\t\t\tChoose what do you want to do? [1 to 6]? ";
		int Choose = clsInputValidate::ReadShortNumberBetween(1, 6);
		return Choose;
	}

	static void _ShowListUsersScreen()
	{
		//cout << "List Users Screen Will Be Here.";
		clsListUsersScreen::ShowListUsers();
	}

	static void _ShowAddNewUserScreen()
	{
		//cout << "Add New User Will be here.";
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		/*cout << "Delete user will be here.";*/
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		/*cout << "Update user will be here.";*/
		clsUpdateUserScreen::UpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		//cout << "Find User will be here.";
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void GoBackToManageUsersMenu()
	{
		cout << setw(37) << left << "" << "\n\n\tPress any key to go back to Manage Users menu...\n";
		system("pause > 0");
		ShowManageUsersMenu();
	}

	static void _PerformManageUsersOptions(enManageUsersMenuOptions Choose)
	{
		switch (Choose)
		{
		case ListUsers:
		{
			system("cls");
			_ShowListUsersScreen();
			GoBackToManageUsersMenu();
			break;
		}
		case AddNewUser:
		{
			system("cls");
			_ShowAddNewUserScreen();
			GoBackToManageUsersMenu();
			break;
		}
		case DeleteUser:
		{
			system("cls");
			_ShowDeleteUserScreen();
			GoBackToManageUsersMenu();
			break;
		}
		case UpdateUser:
		{
			system("cls");
			_ShowUpdateUserScreen();
			GoBackToManageUsersMenu();
			break;
		}
		case FindUser:
		{
			system("cls");
			_ShowFindUserScreen();
			GoBackToManageUsersMenu();
			break;
		}
		case MainMenu:
		{
			system("cls");
			clsMainScreen::ShowMainMenu();
			break;
		}
		}
	}

public:
	static void ShowManageUsersMenu()
	{
		if (!_CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return;
		}
		system("cls");
		_DrawScreenHeader("\t  Manage Users Screen");

		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t\t  Manage Users Menu\n";
		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
		cout << setw(37) << left << "" << "============================================\n";

		_PerformManageUsersOptions((enManageUsersMenuOptions)_ReadManageUsersMenuOptions());
	}
};