#include <gtest/gtest.h>
#include "BankDatabase.hpp"
#include "../Account/Account.hpp"
#include "FileHandler.hpp"

Account myAccount_a("Erick", 100);
Account myAccount_b("Emily", 10000);
Account myAccount_c("Tom", 10000);

bool EqualAcc(Account a, Account b);
void PrepFiles();
void CleanUp();
void AddDefaultEntries(BankDb &TargetDb);

void AddDefaultEntries(BankDb &TargetDb)
{
    TargetDb.AddEntry(myAccount_a);
    TargetDb.AddEntry(myAccount_b);
    TargetDb.AddEntry(myAccount_c);
}

void CleanUp()
{
    fileRemove("MyEmptyDb");
}

void PrepTests()
{
    ResetIdCounter();
    fileRemove("MyEmptyDb");
}

bool EqualAcc(Account a, Account b)
{
    if (a == b)
        return true;
    else
        return false;
}

TEST(AccountUnitTests, CreateDatabase)
{
    BankDb myDb("SaveMyName");
    ASSERT_EQ("SaveMyName", myDb.GetDbName());
}

TEST(AccountUnitTests, AddEntryCreateDbFileExists)
{
    PrepTests();
    Account myAccount("Erick", 100);
    BankDb myDb("MyEmptyDb");
    myDb.AddEntry(myAccount);
    ASSERT_EQ(true, fileExists("MyEmptyDb"));
    CleanUp();
}

TEST(AccountUnitTests, AddEntryReadEntry)
{
    PrepTests();
    Account myAccount("Erick", 100);
    BankDb myDb("MyEmptyDb");
    myDb.AddEntry(myAccount);
    Account ReadEntry = myDb.GetDbEntryByIndex(0);
    ASSERT_EQ(true, ReadEntry == myAccount);
    CleanUp();
}

TEST(AccountUnitTests, TrowExeptionIfDbDoesNotExists)
{
    PrepTests();
    BankDb myDb("MyEmptyDb");
    ASSERT_THROW(myDb.GetDbEntryByIndex(0), std::runtime_error);
    CleanUp();
}

TEST(AccountUnitTests, Add2EntriesRead2nd)
{
    PrepTests();
    BankDb myDb("MyEmptyDb");
    myDb.AddEntry(myAccount_a);
    myDb.AddEntry(myAccount_b);
    Account ReadEntry = myDb.GetDbEntryByIndex(1);
    ASSERT_EQ(ReadEntry.getOwner(), "Emily");
    ASSERT_EQ(ReadEntry.getBalance(), 10000);
    ASSERT_EQ(ReadEntry.getId(), 1);
    CleanUp();
}

TEST(AccountUnitTests, Add3EntriesRead3_REVERSEORDER)
{
    PrepTests();

    BankDb myDb("MyEmptyDb");
    AddDefaultEntries(myDb);
    Account ReadEntry_x = myDb.GetDbEntryByIndex(2);
    ASSERT_EQ(true, ReadEntry_x == myAccount_c);
    Account ReadEntry_y = myDb.GetDbEntryByIndex(0);
    ASSERT_EQ(true, ReadEntry_y == myAccount_a);
    Account ReadEntry_z = myDb.GetDbEntryByIndex(1);
    ASSERT_EQ(true, ReadEntry_z == myAccount_b);

    CleanUp();
}

TEST(AccountUnitTests, Add1EntryRead2ndThrowException)
{
    PrepTests();
    BankDb myDb("MyEmptyDb");
    myDb.AddEntry(myAccount_a);
    ASSERT_THROW(myDb.GetDbEntryByIndex(1), std::out_of_range);
    CleanUp();
}

TEST(AccountUnitTests, Add3EntriesGetAll3Entries)
{
    PrepTests();
    BankDb myDb("MyEmptyDb");
    AddDefaultEntries(myDb);
    ASSERT_EQ(true, myDb.GetDbEntryByIndex(0) == myAccount_a);
    ASSERT_EQ(true, myDb.GetDbEntryByIndex(1) == myAccount_b);
    ASSERT_EQ(true, myDb.GetDbEntryByIndex(2) == myAccount_c);
    CleanUp();
}

TEST(AccountUnitTests, Add3EntriesGetAllasVector)
{
    PrepTests();
    BankDb myDb("MyEmptyDb");
    AddDefaultEntries(myDb);
    ASSERT_EQ(3, myDb.GetNumOfClients());

    std::vector<Account> ReadList = myDb.GetAllEntries();
    ASSERT_EQ(3, ReadList.size());
    ASSERT_EQ(true, EqualAcc(myAccount_a, ReadList[0]));
    ASSERT_EQ(true, EqualAcc(myAccount_b, ReadList[1]));
    ASSERT_EQ(true, EqualAcc(myAccount_c, ReadList[2]));
    CleanUp();
}

TEST(AccountUnitTests, Add3EntriesDelete1EntryGetAll2Entries)
{
    PrepTests();

    BankDb myDb("MyEmptyDb");
    AddDefaultEntries(myDb);
    ASSERT_EQ(3, myDb.GetNumOfClients());
    myDb.DeleteEntryByIndex(0);
    ASSERT_EQ(2, myDb.GetNumOfClients());
    std::vector<Account> ReadList = myDb.GetAllEntries();
    ASSERT_EQ(true, EqualAcc(myAccount_b, ReadList[0]));
    ASSERT_EQ(true, EqualAcc(myAccount_c, ReadList[1]));
    CleanUp();
}

TEST(AccountUnitTests, Add3EntryChangeDepositGetEntryCorrectBalance)
{
    PrepTests();
    BankDb myDb("MyEmptyDb");
    AddDefaultEntries(myDb);

    Account accBeforeChange = myDb.GetDbEntryByIndex(0);
    float initialBalance = accBeforeChange.getBalance();
    accBeforeChange.deposit(200);
    myDb.UpdateEntry(accBeforeChange, 0);

    Account accAfterChange = myDb.GetDbEntryByIndex(0);
    float finalBalance = accAfterChange.getBalance();
    ASSERT_EQ(initialBalance + 200, finalBalance);
    CleanUp();
}

TEST(AccountUnitTests, Add3EntryChangeSubBalanceGetEntryCorrectBalance)
{
    PrepTests();
    BankDb myDb("MyEmptyDb");
    AddDefaultEntries(myDb);

    Account accBeforeChange = myDb.GetDbEntryByIndex(0);
    float initialBalance = accBeforeChange.getBalance();
    accBeforeChange.withdrawal(200);
    myDb.UpdateEntry(accBeforeChange, 0);

    Account accAfterChange = myDb.GetDbEntryByIndex(0);
    float finalBalance = accAfterChange.getBalance();
    ASSERT_EQ(initialBalance - 200, finalBalance);
    CleanUp();
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}