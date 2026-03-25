#pragma once
#pragma once
#include <iostream>
#include <string>
#include "clsScreen.h"
#include "clsBankClient1.h"
class clsShowTransferLogScreen : protected clsScreen
{
private:
    static void PrintTransferRecordLine(clsBankClient1::stTransferRegisterRecord TransferRegisterRecord)
    {
        cout << setw(8) << left << "" << "| " << left << setw(23) << TransferRegisterRecord.DateAndTime;
        cout << "| " << setw(8) << left << TransferRegisterRecord.SourceAccountNumber;
        cout << "| " << setw(8) << left << TransferRegisterRecord.DestinationAccountNumber;
        cout << "| " << setw(8) << left << TransferRegisterRecord.Amount;
		cout << "| " << setw(10) << left << TransferRegisterRecord.SourceAccountBalance;//After
        cout << "| " << setw(10) << left << TransferRegisterRecord.DestinationAccountBalance;//After
		cout << "| " << setw(8) << left << TransferRegisterRecord.UserName;
    }

public:
    static void ShowLoginTransferLogScreen()
    {
        vector <clsBankClient1::stTransferRegisterRecord> vTransferLogRecord = clsBankClient1::GetTransferRegisterList();
        string Title = "\t  Transfer Log List Screen";
        string Subtitle = "\t    (" + to_string(vTransferLogRecord.size()) + ") Record(s). ";

        _DrawScreenHeader(Title, Subtitle);

        cout << "\n\t_______________________________________________________";
        cout << "________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";
        cout << "\n\t_______________________________________________________";
        cout << "________________________________________________\n" << endl;

        if (vTransferLogRecord.size() == 0)
            cout << "\t\t\t\tNo Transfers Available In the System!";
        else
            for (clsBankClient1::stTransferRegisterRecord& TransferRegister : vTransferLogRecord)
            {
                PrintTransferRecordLine(TransferRegister);
                cout << endl;
            }

        cout << "\n\t_______________________________________________________";
        cout << "________________________________________________\n" << endl;

    }
};

