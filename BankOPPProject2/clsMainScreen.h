#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListClients.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsShowLoginRegisterScreen.h"

using namespace std;

class clsTransactionScreen;

class clsMainScreen : protected clsScreen
{
private:
	enum enMainMenuOptions
	{
		ShowClientList = 1, AddNewClient = 2, DeleteClient = 3
		, UpdateClientInfo = 4, FindClient = 5, Transactions = 6,
		MangageUsers = 7,ShowRegisterLogin = 8 ,CurrencyExchange = 9,Logout = 10
	};

	static int _ReadMainMenuOptions()
	{
		cout << setw(37) << left << "\t\t\t\t\tChoose what do you want to do? [1 to 10]? ";
		int Choose = clsInputValidate::ReadShortNumberBetween(1, 10);
		return Choose;
	}

	static void _ShowAllClientsListScreen()
	{
		clsListClients::ShowListClients();
	}

	static void _ShowAddNewClientScreen()
	{
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _ShowDeleteClientScreen()
	{
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen()
	{
		clsUpdateClientScreen::UpdateClientScreen();
	}

	static void _ShowFindClientScreen()
	{
		//cout << "Find Client Screen Will Be Here.";
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsScreen();

	static void _ShowManageUsersScreen();

	static void _ShowRegisterLoginScreen()
	{
		clsShowLoginRegisterScreen::ShowLoginRegisterScreen();
	}

	static void _ShowCurrencyExchangeScreen();

	static void _Logout();

	static void GoBackToMainMenu()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to main menu...\n";
		system("pause > 0");
		ShowMainMenu();
	}

	static void _PerformMainMenuOptions(enMainMenuOptions Choose)
	{
		switch (Choose)
		{
		case clsMainScreen::ShowClientList:
		{
			system("cls");
			_ShowAllClientsListScreen();
			GoBackToMainMenu();
			break;
		}
		case clsMainScreen::AddNewClient:
		{
			system("cls");
			_ShowAddNewClientScreen();
			GoBackToMainMenu();
			break;
		}
		case clsMainScreen::DeleteClient:
		{
			system("cls");
			_ShowDeleteClientScreen();
			GoBackToMainMenu();
			break;
		}
		case clsMainScreen::UpdateClientInfo:
		{
			system("cls");
			_ShowUpdateClientScreen();
			GoBackToMainMenu();
			break;
		}
		case clsMainScreen::FindClient:
		{
			system("cls");
			_ShowFindClientScreen();
			GoBackToMainMenu();
			break;
		}
		case clsMainScreen::Transactions:
		{
			system("cls");
			_ShowTransactionsScreen();
			GoBackToMainMenu();
		break;
		}
		case clsMainScreen::MangageUsers:
		{
			system("cls");
			_ShowManageUsersScreen();
			GoBackToMainMenu();
			break;
		}
		case clsMainScreen::ShowRegisterLogin:
		{
			system("cls");
			_ShowRegisterLoginScreen();
			GoBackToMainMenu();
			break;
		}
		case clsMainScreen::CurrencyExchange:
		{
			system("cls");
			_ShowCurrencyExchangeScreen();
			GoBackToMainMenu();
			break;
		}
		case clsMainScreen::Logout:
		{
			system("cls");
			_Logout();
			break;
		}
		}
	}

public :
	static void ShowMainMenu()
	{
		system("cls");
		clsMainScreen::_DrawScreenHeader("\t\tMain Screen");
		
		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Register Login.\n";
		cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
		cout << setw(37) << left << "" << "\t[10] Logout.\n";
		cout << setw(37) << left << "" << "============================================\n";

		_PerformMainMenuOptions((enMainMenuOptions)_ReadMainMenuOptions());
	} 
};

