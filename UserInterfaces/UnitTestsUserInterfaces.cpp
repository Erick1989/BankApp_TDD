#include <gtest/gtest.h>
#include "UserInterface.hpp"
#include "../Database/BankDatabase.hpp"
#include "../Account/Account.hpp"
#include "Screens/OpenAccount.hpp"
#include "Screens/BalanceEnquire.hpp"
#include "Screens/Deposit.hpp"
#include "Screens/Withdrawal.hpp"
#include "Screens/CloseAccount.hpp"
#include "Screens/ShowAllAccounts.hpp"


bool EqualAcc(Account a, Account b);
bool EqualAcc(Account a, Account b)
{
    if (a == b)
        return true;
    else
        return false;
}

Account myAccount_a("Erick", 100);
Account myAccount_b("Emily", 10000);
Account myAccount_c("Tom", 10000);


TEST(UserInterfaceTests, CreateAccountOverUi)
{
    fileRemove("MyDummyDb");
    ResetIdCounter();
    OpenAccount OpenAcc;
    BankDb Database("MyDummyDb");   
    Account myAccount("Erick", 100);
    OpenAcc.setDatabaseLink(&Database);
    OpenAcc.SaveAccountInDb(myAccount);
    ASSERT_EQ(true, fileExists("MyDummyDb"));
    ResetIdCounter();
    fileRemove("MyDummyDb");
}

TEST(UserInterfaceTests, BalanceEnquireOverUi)
{
    fileRemove("MyDummyDb");
    ResetIdCounter();
    OpenAccount OpenAcc;
    BalanceEnquire uiBalanceEnquire;
    BankDb Database("MyDummyDb");   
    OpenAcc.setDatabaseLink(&Database);
    OpenAcc.SaveAccountInDb(myAccount_a);
    OpenAcc.SaveAccountInDb(myAccount_b);
    OpenAcc.SaveAccountInDb(myAccount_c);
    ASSERT_EQ(true,EqualAcc(uiBalanceEnquire.CollectAccountByIndex(0),myAccount_a));
    ASSERT_EQ(true,EqualAcc(uiBalanceEnquire.CollectAccountByIndex(1),myAccount_b));
    ASSERT_EQ(true,EqualAcc(uiBalanceEnquire.CollectAccountByIndex(2),myAccount_c));
    ResetIdCounter();
    fileRemove("MyDummyDb");
}

TEST(UserInterfaceTests, DepositAndCheckAccount)
{
    fileRemove("MyDummyDb");
    ResetIdCounter();
    OpenAccount OpenAcc;
    BalanceEnquire uiBalanceEnquire;
    Deposit uiDeposit;
    BankDb Database("MyDummyDb");   
    OpenAcc.setDatabaseLink(&Database);
    OpenAcc.SaveAccountInDb(myAccount_a);
    OpenAcc.SaveAccountInDb(myAccount_b);
    uiDeposit.DepositIntoAcc(0,100);
    uiDeposit.DepositIntoAcc(1,100);
    ASSERT_EQ(uiBalanceEnquire.CollectAccountByIndex(0).getBalance(),myAccount_a.getBalance()+100);
    ASSERT_EQ(uiBalanceEnquire.CollectAccountByIndex(1).getBalance(),myAccount_b.getBalance()+100);
    ResetIdCounter();
    fileRemove("MyDummyDb");
}

TEST(UserInterfaceTests, WithdrawalAndCheckAccount)
{
    fileRemove("MyDummyDb");
    ResetIdCounter();
    OpenAccount OpenAcc;
    BalanceEnquire uiBalanceEnquire;
    BankDb Database("MyDummyDb");
    OpenAcc.setDatabaseLink(&Database);

    Withdrawal uiWithdrawal;   
    OpenAcc.SaveAccountInDb(myAccount_a);
    OpenAcc.SaveAccountInDb(myAccount_b);
    uiWithdrawal.WithdrawalFromAcc(0,100);
    uiWithdrawal.WithdrawalFromAcc(1,100);
    ASSERT_EQ(uiBalanceEnquire.CollectAccountByIndex(0).getBalance(),myAccount_a.getBalance()-100);
    ASSERT_EQ(uiBalanceEnquire.CollectAccountByIndex(1).getBalance(),myAccount_b.getBalance()-100);
    ResetIdCounter();
    fileRemove("MyDummyDb");
}


TEST(UserInterfaceTests, GetAllClients){
    fileRemove("MyDummyDb");
    ResetIdCounter();
    OpenAccount OpenAcc;
    BankDb Database("MyDummyDb");
    OpenAcc.setDatabaseLink(&Database);
    ShowAllAcc uiShowAllAccounts;   
    OpenAcc.SaveAccountInDb(myAccount_a);
    OpenAcc.SaveAccountInDb(myAccount_b);
    OpenAcc.SaveAccountInDb(myAccount_c);
    std::vector<Account> AllClients= uiShowAllAccounts.GetAllClients();
    ASSERT_EQ(true, EqualAcc(myAccount_a,AllClients[0]));
    ASSERT_EQ(true, EqualAcc(myAccount_b,AllClients[1]));
    ASSERT_EQ(true, EqualAcc(myAccount_c,AllClients[2]));
}

TEST(UserInterfaceTests, DeleteOneAccount){
    fileRemove("MyDummyDb");
    ResetIdCounter();
    OpenAccount OpenAcc;
    BankDb Database("MyDummyDb");
    OpenAcc.setDatabaseLink(&Database);
    CloseAccount uiCloseAccount;   
    ShowAllAcc uiShowAllAccounts;
    OpenAcc.SaveAccountInDb(myAccount_a);
    OpenAcc.SaveAccountInDb(myAccount_b);
    OpenAcc.SaveAccountInDb(myAccount_c);
    uiCloseAccount.CloseAccountByIndex(0);
    std::vector<Account> AllClients= uiShowAllAccounts.GetAllClients();
    ASSERT_EQ(true, EqualAcc(myAccount_b,AllClients[0]));
    ASSERT_EQ(true, EqualAcc(myAccount_c,AllClients[1]));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}