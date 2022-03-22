#ifndef BANKDATABASE_HPP
#define BANKDATABASE_HPP
#include <string>
#include "../Account/Account.hpp"
#include "FileHandler.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <stdexcept>

class BankDb
{
public:
    BankDb(std::string FileName);
    ~BankDb();
    std::vector<Account> GetAllEntries();
    std::string GetDbName();
    Account GetDbEntryByIndex(int index);
    int GetNumOfClients();
    void UpdateDatabase(std::vector<Account> NewAccounts);
    void DeleteEntryByIndex(int index);
    void AddEntry(Account NewClient);
    void UpdateEntry(Account NewClient, int index);

private:
    void OpenWriteConnection();
    void OpenReadConnection();
    void CloseConnection();
    std::string FileName;
    std::fstream DbStream;
    Account ReadAccountEntry(int index);
    std::string ReadOwner(std::string line);
    float ReadBalance(std::string line);
    int ReadClientId(std::string line);
    std::string GetAccountLine(std::string line);
    std::string GetBalanceLine(std::string line);
    int GetNumAccounts();
    float ParseBalance(std::string BalanceLine);
    std::string ParseOwner(std::string AccountLine);
    std::string GetClientIdLine(std::string line);
    int ParseClientId(std::string ClientIdLine);
    std::string RetriveAccountTxt(int index);
    int NumOfClients;

    enum{
        open_for_read=0,
        open_for_write=1,
        closed
    }DbFileState;
    
protected:
};
#endif