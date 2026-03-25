#pragma once
#include <iostream>
#include <string>
#include "clsBankClient1.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalanceScreen.h"
#include "clsShowTransferScreen.h"
#include "clsShowTransferLogScreen.h"
using namespace std;

class clsTransactionScreen : protected clsScreen
{
private :
	enum enTransactionMenuOptions
	{
		Deposit = 1, Withdraw = 2, TotalBalances = 3,Transfer = 4,TransferLog = 5,MainMenu = 6
	};

	static int _ReadTransactionMenuOptions()
	{
		cout << setw(37) << left << "\t\t\t\t\tChoose what do you want to do? [1 to 6]? ";
		int Choose = clsInputValidate::ReadShortNumberBetween(1, 6);
		return Choose;
	}

	static void _ShowDepositScreen()
	{
		//cout << "Deposit Screen Will Be Here...";
		clsDepositScreen::_ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		//cout << "Withdraw Screen Will Be Here...";
		clsWithdrawScreen::_ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		//cout << "Total Balances Screen Will Be Here...";
		clsTotalBalanceScreen::ShowTotalBalances();
	}

	static void _ShowTransferScreen()
	{
		//cout << "Transfer Screen Will Be Here...";
		clsShowTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen()
	{
		//cout << "Transfer Log Screen Will Be Here...";
		clsShowTransferLogScreen::ShowLoginTransferLogScreen();
	}

	static void GoBackToTransactionMenu()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to transaction menu...\n";
		system("pause > 0");
		ShowTransactionMenu();
	}

	static void _PerformTransactionMenuOptions(enTransactionMenuOptions Choice)
	{
		switch (Choice)
		{
		case clsTransactionScreen::Deposit:
		{
			system("cls");
			_ShowDepositScreen();
			GoBackToTransactionMenu();
			break;
		}
		case clsTransactionScreen::Withdraw:
		{
			system("cls");
			_ShowWithdrawScreen();
			GoBackToTransactionMenu();
			break;
		}
		case clsTransactionScreen::TotalBalances:
		{
			system("cls");
			_ShowTotalBalancesScreen();
			GoBackToTransactionMenu();
			break;
		}

		case clsTransactionScreen::Transfer:
		{
			system("cls");
			_ShowTransferScreen();
			GoBackToTransactionMenu();
			break;
		}

		case clsTransactionScreen::TransferLog:
		{
			system("cls");
			_ShowTransferLogScreen();
			GoBackToTransactionMenu();
			break;
		}
		case clsTransactionScreen::MainMenu:
		{
			system("cls");
			clsMainScreen::ShowMainMenu();
		}
		}
	}

public :
	static void ShowTransactionMenu()
	{
		if (!_CheckAccessRights(clsUser::enPermissions::pTransactions))
		{
			return;
		}
		system("cls");
		clsTransactionScreen::_DrawScreenHeader("\t   Transaction Screen");

		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t\t   Transaction Menu\n";
		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] TransferLog.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
		cout << setw(37) << left << "" << "============================================\n";

		_PerformTransactionMenuOptions((enTransactionMenuOptions)_ReadTransactionMenuOptions());
	}
};

