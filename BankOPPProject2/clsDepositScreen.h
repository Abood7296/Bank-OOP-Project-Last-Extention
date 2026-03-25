#pragma once
#include <iostream>
#include <string>
#include "clsScreen.h"
#include "clsBankClient1.h"
#include "clsInputValidate.h"

using namespace std;

class clsDepositScreen : protected clsScreen
{
private :
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
	static void _ShowDepositScreen()
	{
		clsDepositScreen::_DrawScreenHeader("\t   Deposit Screen");

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

		cout << "\nPlease Enter Deposit Amount ?\n";
		Amount = clsInputValidate::ReadDblNumber();

		cout << "\nAre You Sure You Want To Perform This Transaction ?\n";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Client1.Deposit(Amount);
			cout << "\nAmount Deposited Successfully.\n";
			cout << "\nNew Balance Is : " << Client1.AccountBalance;
		}
		else
		{
			cout << "\nOperation Was Cancelled.\n";
		}
	}
};

