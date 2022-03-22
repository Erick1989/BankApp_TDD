#include "UserInterfaces/UserInterface.hpp"
#include "UserInterfaces/Screens/StartUi.hpp"
#include "UserInterfaces/Screens/OpenAccount.hpp"
#include "UserInterfaces/Screens/BalanceEnquire.hpp"
#include "UserInterfaces/Screens/Deposit.hpp"
#include "UserInterfaces/Screens/Withdrawal.hpp"
#include "UserInterfaces/Screens/CloseAccount.hpp"
#include "UserInterfaces/Screens/ShowAllAccounts.hpp"
#include "Database/BankDatabase.hpp"
#include "Account/Account.hpp"
#include <iostream>

int main()
{
    Account Mytest("Erick",100);
    BankDb DatabaseLink("ClientsDatabase");
    UserInterface MasterInterface;
    MasterInterface.setDatabaseLink(&DatabaseLink);
    StartUi UiStart;
    OpenAccount UiOpenAccount;
    BalanceEnquire UiBalanceEnquire;
    Deposit UiDeposit;
    Withdrawal UiWithdrawal;
    CloseAccount UiCloseAccount;
    ShowAllAcc UiShowAllAcc;
    UserInterface * _Addr[]={&UiStart,&UiOpenAccount,&UiBalanceEnquire,
                             &UiDeposit,&UiWithdrawal,&UiCloseAccount,
                             &UiShowAllAcc};
    MasterInterface.setUiBaseAddr(_Addr);
    UserInterface * UI=&UiStart;
    UserInterface::MenuValues ValMenu;

    while (UI!=nullptr)
    {
        UI=UI->Exec();
    }
    
}