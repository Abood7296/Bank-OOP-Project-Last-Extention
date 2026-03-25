#include "clsMainScreen.h"
#include "clsTransactionScreen.h"
#include "clsManageUsers.h"
#include "clsLoginScreen.h"
#include "clsCurrencyScreen.h"
#include "Global.h"

void clsMainScreen::_ShowTransactionsScreen()
{
    clsTransactionScreen::ShowTransactionMenu();
}

void clsMainScreen::_ShowManageUsersScreen()
{
    clsManageUsers::ShowManageUsersMenu();
}

void clsMainScreen::_Logout()
{
    CurrentUser = clsUser::Find("", "");
    clsLoginScreen::ShowLoginScreen();
}

void clsMainScreen::_ShowCurrencyExchangeScreen()
{
    clsCurrencyScreen::ShowCurrencyExchangeMenu();
}