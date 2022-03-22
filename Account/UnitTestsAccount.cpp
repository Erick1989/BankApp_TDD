#include <gtest/gtest.h>
#include "Account.hpp"

TEST(AccountUnitTests, CreateElementZero)
{
    ResetIdCounter();
    Account myAccount("Erick",100);
    ASSERT_EQ(100, myAccount.getBalance());
    ASSERT_EQ(0, myAccount.getId());
    ASSERT_EQ("Erick", myAccount.getOwner());
}

TEST(AccountUnitTests, InitialBalanceGreaterThan99_99)
{
    ResetIdCounter();
    ASSERT_THROW(Account("Erick",99.98),std::invalid_argument);
}

TEST(AccountUnitTests, Deposit100Balance100More)
{
    ResetIdCounter();
    Account myAccount("Erick",100);
    myAccount.deposit(100);
    ASSERT_EQ(200,myAccount.getBalance());
}

TEST(AccountUnitTests, DepositMustNotBeNegative)
{
    ResetIdCounter();
    Account myAccount("Erick",100);
    ASSERT_THROW(myAccount.deposit(-100),std::invalid_argument);
}

TEST(AccountUnitTests, Start100Widrawal50Balance50)
{
    ResetIdCounter();
    Account myAccount("Erick",100);
    myAccount.withdrawal(50.00);
    ASSERT_EQ(50,myAccount.getBalance());
}

TEST(AccountUnitTests, WithdrawalMustNotBeNegative)
{
    ResetIdCounter();
    Account myAccount("Erick",100);
    ASSERT_THROW(myAccount.withdrawal(-100),std::invalid_argument);
}

TEST(AccountUnitTests, BalanceMustNotBeLessThan1000)
{
    ResetIdCounter();
    Account myAccount("Erick",100);
    ASSERT_THROW(myAccount.withdrawal(1100),std::invalid_argument);
}

TEST(AccountUnitTests, PositiveBalanceShallCreatePositiveString)
{
    ResetIdCounter();
    Account myAccount("Erick",100);
    ASSERT_EQ(myAccount.CreateStream(),"Account Owner: Erick<\nBalance: +100.00<\nClient Id: 0<\n");
}

TEST(AccountUnitTests, NegativeBalanceShallCreateNegativeString)
{
    ResetIdCounter();
    Account myAccount("Erick",100);
    myAccount.withdrawal(200);
    ASSERT_EQ(myAccount.CreateStream(),"Account Owner: Erick<\nBalance: -100.00<\nClient Id: 0<\n");
}

TEST(AccountUnitTests, EqualAccountsReturnTrue)
{
    ResetIdCounter();
    Account myAccount1("Erick",100);
    ASSERT_EQ(true,myAccount1==myAccount1);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}