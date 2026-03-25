#pragma once
#include <iostream>
#include <string>
#include "clsScreen.h"
#include "clsBankClient1.h"
#include "clsInputValidate.h"
#include "Global.h"
class clsShowTransferScreen : protected clsScreen
{
private:
	static void _PrintClient(clsBankClient1 Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}

	static void Withdraw(string AccountNumber, double &Amount)
	{
		clsBankClient1 Client1 = clsBankClient1::Find(AccountNumber);

		Amount = clsInputValidate::ReadDblNumber();

		while (Amount > Client1.AccountBalance)
		{
			cout << "\nAmount is greater than Balance, Please Choose Another Amount : ";
			Amount = clsInputValidate::ReadDblNumber();
		}
	}

	/*static void TransferScreen()
	{
		string SourceAccountNumber = "";

		cout << "\nPlease Enter Account Number To Transfer From: ";
		SourceAccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient1::IsClientExist(SourceAccountNumber))
		{
			cout << "\nClient With [" << SourceAccountNumber << "], choose another one: ";
			SourceAccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient1 SourceClient = clsBankClient1::Find(SourceAccountNumber);
		_PrintClient(SourceClient);

		char Answer = 'y';
		double Amount = 0;

		string DestinationAccountNumber = "";
		cout << "\nPlease Enter Account Number To Transfer To ?\n";
		DestinationAccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient1::IsClientExist(DestinationAccountNumber))
		{
			cout << "\nClient With [" << DestinationAccountNumber << "], choose another one: ";
			DestinationAccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient1 DestinationClient = clsBankClient1::Find(DestinationAccountNumber);
		_PrintClient(DestinationClient);

		cout << "Enter Transfer Amount ?\n";
		Withdraw(SourceAccountNumber, Amount);

		cout << "\nAre You Sure You Want To Perform This Transaction ?\n";
		cin >> Answer;

		if(Answer == 'y' || Answer == 'Y')
		if (SourceClient.Withdraw(Amount))
		{
			cout << "\nTransfer Done Successfully.\n";
			DestinationClient.Deposit(Amount);
		}
		else
		{
			cout << "\nOperation Was Cancelled.\n";
		}
		SourceClient.RegisterTransferLog(DestinationClient, Amount);
		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);
	}*/

	static string _ReadAccountNumber()
	{
		string AccountNumber;
		cout << "\nPlease Enter Account Number to Transfer From: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient1::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}

	static float ReadAmount(clsBankClient1 SourceClient)
	{
		float Amount;

		cout << "\nEnter Transfer Amount? ";

		Amount = clsInputValidate::ReadFloatNumber();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			Amount = clsInputValidate::ReadDblNumber();
		}
		return Amount;
	}

public:
	//static void ShowTransferScreen()
	//{
	//	//This Solution From Me -).
	//	clsShowTransferScreen::_DrawScreenHeader("\t   Transfer Screen");
	//	TransferScreen();
	//}

	static void ShowTransferScreen()
	{
		//This Solution From Abu-Hadhoud AL Fakhm.
		_DrawScreenHeader("\tTransfer Screen");

		clsBankClient1 SourceClient = clsBankClient1::Find(_ReadAccountNumber());

		_PrintClient(SourceClient);

		clsBankClient1 DestinationClient = clsBankClient1::Find(_ReadAccountNumber());

		_PrintClient(DestinationClient);

		float Amount = ReadAmount(SourceClient);


		cout << "\nAre you sure you want to perform this operation? y/n? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.UserName))
			{
				cout << "\nTransfer done successfully\n";
			}
			else
			{
				cout << "\nTransfer Failed \n";
			}
		}

		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);


	}
};

