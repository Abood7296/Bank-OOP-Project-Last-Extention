#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsFindCurrencyScreen : protected clsScreen
{
	private:
	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:";
		cout << "\n___________________";
		cout << "\nCountry  : " << Currency.Country();
		cout << "\nCode     : " << Currency.CurrencyCode();
		cout << "\nName     : " << Currency.CurrencyName();
		cout << "\nRate(1$) : " << Currency.Rate();
		cout << "\n___________________\n";
	}

    static clsCurrency _FindCurrencyByCode()
    {
        string CurrencyCode = "";
        cout << "\nPlease Enter Currency Code: ";
        CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExistByCode(CurrencyCode))
        {
            cout << "\nCurrency Code is Not Found, Choose another one: ";
            CurrencyCode = clsInputValidate::ReadString();
        }
        return clsCurrency::FindByCode(CurrencyCode);
	}

    static clsCurrency _FindCurrencyByCountry()
    {
        string Country = "";
        cout << "\nPlease Enter Country Name: ";
        Country = clsInputValidate::ReadString();
        while (!clsCurrency::IsCurrencyExistByCountry(Country))
        {
            cout << "\nCountry Name is Not Found, Choose another one: ";
            Country = clsInputValidate::ReadString();
        }
        return clsCurrency::FindByCountry(Country);
    }

public:
	static void ShowFindCurrencyScreen()
	{
        _DrawScreenHeader("\t Find Currency Screen");
		short FindBy = 0;

        cout << "Find By: [1] Code Or [2] Country ? ";
		FindBy = clsInputValidate::ReadShortNumberBetween(1, 2, "Invalid Number");

        clsCurrency* Currency = nullptr;

        if (FindBy == 1)
        {
			Currency = new clsCurrency(_FindCurrencyByCode());
        }
        else if(FindBy == 2)
        {
            Currency = new clsCurrency(_FindCurrencyByCountry());
        }
        if (!Currency->IsEmpty())
        {
            cout << "\nCurrency Found :-)\n";
        }
        else
        {
            cout << "\nCurrency Was not Found :-(\n";
        }
        _PrintCurrency(*Currency);
		delete Currency;
    }
};

