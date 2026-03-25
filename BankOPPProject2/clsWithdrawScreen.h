#pragma once
#include <iostream>
#include <string>
#include "clsScreen.h"
#include "clsBankClient1.h"
#include "clsInputValidate.h"

using namespace std;

class clsWithdrawScreen : clsScreen
{
private:
	static void _PrintClient(clsBankClient1 Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}

public :
	static void _ShowWithdrawScreen()
	{
		clsWithdrawScreen::_DrawScreenHeader("\t   Withdraw Screen");

		string AccountNumber = "";

		cout << "\nPlease Enter client Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient1::IsClientExist(AccountNumber))
		{
			cout << "\nClient With [" << AccountNumber << "], choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient1 Client1 = clsBankClient1::Find(AccountNumber);
		_PrintClient(Client1);

		char Answer = 'y';
		double Amount = 0;

		cout << "\nPlease Enter Withdraw Amount ?\n";
		Amount = clsInputValidate::ReadDblNumber();

		while (Amount > Client1.AccountBalance)
		{
			cout << "\nAmount is greater than Balance, Please Choose Another Amount : ";
			Amount = clsInputValidate::ReadDblNumber();
		}

		cout << "\nAre You Sure You Want To Perform This Transaction ?\n";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (Client1.Withdraw(Amount))
			{
				cout << "Amount Withdraw Successfully.\n";
				cout << "\nNew Balance Is : " << Client1.AccountBalance;
			}
		}
		else
		{
			cout << "\nOperation Was Cancelled\n";
			cout << "Your Balance is : " << Client1.AccountBalance;
		}
	}
};

