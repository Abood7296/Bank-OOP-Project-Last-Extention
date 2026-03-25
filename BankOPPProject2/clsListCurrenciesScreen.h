#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsCurrency.h"
using namespace std;

class clsListCurrenciesScreen : protected clsScreen
{
private:
    static void PrintCurrencyRecordLine(clsCurrency Currency)
    {
        cout << setw(8) << left << "" << "| " << left << setw(30) << Currency.Country();
        cout << "| " << setw(10) << left << Currency.CurrencyCode();
        cout << "| " << setw(40) << left << Currency.CurrencyName();
        cout << "| " << setw(10) << left << Currency.Rate();
    }

public:
    static void ShowListCurrencies()
    {
        vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();
        string Title = "\t  Currencies List Screen";
        string Subtitle = "\t    (" + to_string(vCurrencies.size()) + ") Currencies ";

        clsListCurrenciesScreen::_DrawScreenHeader(Title, Subtitle);

        cout << "\n\t_______________________________________________________";
        cout << "________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(10) << "Code";
        cout << "| " << left << setw(40) << "Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";
        cout << "\n\t_______________________________________________________";
        cout << "________________________________________________\n" << endl;

        if (vCurrencies.size() == 0)
            cout << "\t\t\t\tNo Currencies Available In the System!";
        else
            for (clsCurrency& Currency : vCurrencies)
            {
                PrintCurrencyRecordLine(Currency);
                cout << endl;
            }

        cout << "\n\t_______________________________________________________";
        cout << "________________________________________________\n" << endl;
    }
};

