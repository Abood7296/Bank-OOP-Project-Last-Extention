#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListCurrenciesScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

class clsCurrencyScreen : protected clsScreen
{
	enum enCurrencyMenuOptions
	{
		ListCurrencies = 1, FindCurrency = 2, UpdateRate = 3, CurrencyCalculator = 4, MainMenu = 5
	};

	static int _ReadCurrencyMenuOptions()
	{
		cout << setw(37) << left << "\t\t\t\t\tChoose what do you want to do? [1 to 5]? ";
		int Choose = clsInputValidate::ReadShortNumberBetween(1, 5);
		return Choose;
	}

	static void _ShowListCurrenciesScreen()
	{
		//cout << "List Currencies Screen Will Be Here.";
		clsListCurrenciesScreen::ShowListCurrencies();
	}

	static void _ShowFindCurrencyScreen()
	{
		/*cout << "Find Currency Screen Will be here.";*/
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		//cout << "Update Rate Screen will be here.";
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		//cout << "Currency Calculator Screen will be here.";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void GoBackToCurrencyMenu()
	{
		cout << setw(37) << left << "" << "\n\n\tPress any key to go back to Currency Menu...\n";
		system("pause > 0");
		ShowCurrencyExchangeMenu();
	}

	static void _PerformCurrencyExchangeOptions(enCurrencyMenuOptions Choose)
	{
		switch (Choose)
		{
		case ListCurrencies:
		{
			system("cls");
			_ShowListCurrenciesScreen();
			GoBackToCurrencyMenu();
			break;
		}
		case FindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			GoBackToCurrencyMenu();
			break;
		}
		case UpdateRate:
		{
			system("cls");
			_ShowUpdateRateScreen();
			GoBackToCurrencyMenu();
			break;
		}
		case CurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			GoBackToCurrencyMenu();
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
	static void ShowCurrencyExchangeMenu()
	{
		if (!_CheckAccessRights(clsUser::enPermissions::pCurrencyExchange))
		{
			return;
		}
		system("cls");
		_DrawScreenHeader("  Currency Exchange Main Screen");

		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t\t Currency Exchange Menu\n";
		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
		cout << setw(37) << left << "" << "============================================\n";

		_PerformCurrencyExchangeOptions((enCurrencyMenuOptions)_ReadCurrencyMenuOptions());
	}
};

