#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "clsBankClient1.h"
#include "clsUtil.h"
#include "clsScreen.h"

using namespace std;

class clsTotalBalanceScreen : protected clsScreen
{
private :
    static void _PrintClientRecordBalanceLine(clsBankClient1 Client)
    {
        cout << setw(25) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
        cout << "\t| " << setw(35) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.AccountBalance;
    }

public :
    static void ShowTotalBalances()
    {
        vector <clsBankClient1> vClients = clsBankClient1::GetClientsList();

        string Title = "\t Total Balances Screen";
        string Subtitle = "\t    (" + to_string(vClients.size()) + ") Clients ";

        _DrawScreenHeader(Title, Subtitle);

        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;

        cout << setw(25) << left << "" << "| " << left << setw(15) << "Account Number";
        cout << "\t| " << left << setw(35) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;

        double TotalBalances = clsBankClient1::GetTotalBalances();

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient1& Client : vClients)
            {
                _PrintClientRecordBalanceLine(Client);
                cout << endl;
            }

        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;
        cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
        cout << "\t\t\t\t\t   ( " << clsUtil::NumberToText(TotalBalances) << " ) ";
    }
};

