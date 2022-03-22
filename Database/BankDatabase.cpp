#ifndef BANKDATABASE_CPP
#define BANKDATABASE_CPP

#include "BankDatabase.hpp"

void verifyValidIndex(int index, int size);

BankDb::BankDb(std::string FileName)
{
    this->FileName = FileName;
    DbFileState=closed;
}

void BankDb::AddEntry(Account NewClient)
{
    this->OpenWriteConnection();
    this->DbStream << "-------------------" << std::endl;
    this->DbStream << NewClient.CreateStream();
    this->DbStream << "-------------------#" << std::endl;
    this->DbStream.close();
}

void BankDb::OpenWriteConnection()
{
    if(DbFileState==open_for_read)
        this->CloseConnection();
    this->DbStream.open(this->FileName, std::ios::app | std::ios::out);
    this->DbFileState=open_for_write;
}

void BankDb::CloseConnection()
{
    this->DbStream.close();
    this->DbFileState=closed;
}

void BankDb::OpenReadConnection()
{
    if(fileExists(this->FileName)==false)
        throw std::runtime_error("Database file does not exists");
    if(DbFileState==open_for_write)
        this->CloseConnection();
    if(this->DbStream.is_open()==false)
        this->DbStream.open(this->FileName, std::ios::in);
    this->DbFileState=open_for_read;
    return;
}

Account BankDb::GetDbEntryByIndex(int index)
{
    this->OpenReadConnection();
    Account a = ReadAccountEntry(index);
    this->CloseConnection();
    return a;
}

Account BankDb::ReadAccountEntry(int index)
{
    std::string TxtBlock = this->RetriveAccountTxt(index);
    Account temp(ReadOwner(TxtBlock), ReadBalance(TxtBlock), ReadClientId(TxtBlock));
    return temp;
}

std::string BankDb::RetriveAccountTxt(int index)
{
    std::string AccountTxtBlock;
    this->DbStream.seekg(0,std::ios::beg);
    if(index<0)
        throw std::out_of_range("Invalid Index.\n");
    for (int i = 0; i <= index; i++)
    {
        getline(this->DbStream, AccountTxtBlock, '#');
        if (this->DbStream.eof())
            throw std::out_of_range("Invalid Index.\n");
    }
    return AccountTxtBlock;
}

int BankDb::GetNumOfClients(){
        this->OpenReadConnection();
        int Accounts=this->GetNumAccounts();
        this->CloseConnection();
    return Accounts;
}

int BankDb::GetNumAccounts(){
    int NumAccounts=0;
    std::string AccountTxtBlock;
    this->DbStream.seekg(0,std::ios::beg);
    while(this->DbStream.eof()==false){
        getline(this->DbStream,AccountTxtBlock, '#');
        NumAccounts++;
    }
    return NumAccounts-1;
}

std::string BankDb::ReadOwner(std::string line)
{
    std::string Owner, AccountLine;
    AccountLine = this->GetAccountLine(line);
    Owner = ParseOwner(AccountLine);
    return Owner;
}

std::string BankDb::GetAccountLine(std::string line)
{
    const std::string del = "Account Owner: ";
    const std::string line_del = "\n";
    int initPos = line.find(del);
    int finalPos = line.find(line_del);
    return line.substr(initPos, finalPos - initPos);
}

std::string BankDb::ParseOwner(std::string AccountLine)
{
    const std::string del = ": ";
    const std::string line_del = "<";

    int initPos = AccountLine.find(del) + del.size();
    int finalPos = AccountLine.find(line_del);
    int NameLen = finalPos - initPos;
    return AccountLine.substr(initPos, NameLen);
}

float BankDb::ReadBalance(std::string line)
{
    std::string BalanceLine = GetBalanceLine(line);
    return this->ParseBalance(BalanceLine);
}

std::string BankDb::GetBalanceLine(std::string line)
{
    std::string del = "Balance: ";
    const std::string line_del = "\n";
    int initPos = line.find(del);
    int finalPos = line.find(line_del) - line.find(del);
    std::string BalanceLine = line.substr(initPos, finalPos - initPos);
    return BalanceLine;
}

float BankDb::ParseBalance(std::string BalanceLine)
{
    const std::string del = ": ";
    const std::string line_del = "<";

    int initPos = BalanceLine.find(del) + del.size();
    int finalPos = BalanceLine.find(line_del);
    int ValLen = finalPos - initPos;
    return std::stod(BalanceLine.substr(initPos, ValLen));
}

int BankDb::ReadClientId(std::string line)
{
    std::string ClientIdLine = this->GetClientIdLine(line);
    return this->ParseClientId(ClientIdLine);
}

std::string BankDb::GetClientIdLine(std::string line)
{
    std::string del = "Client Id: ";
    const std::string line_del = "\n";
    int initPos = line.find(del);
    int finalPos = line.find(line_del) - line.find(del);
    std::string ClientIdLine = line.substr(initPos, finalPos - initPos);
    return ClientIdLine;
}

int BankDb::ParseClientId(std::string ClientIdLine)
{
    const std::string del = ": ";
    const std::string line_del = "<";

    int initPos = ClientIdLine.find(del) + del.size();
    int finalPos = ClientIdLine.find(line_del);
    int ValLen = finalPos - initPos;
    return std::stoi(ClientIdLine.substr(initPos, ValLen));
}

std::string BankDb::GetDbName()
{
    return this->FileName;
}

std::vector<Account> BankDb::GetAllEntries(){
    this->OpenReadConnection();
    int size=this->GetNumAccounts();
    std::vector<Account> temp(size,Account("",0,-1));
    for( int i=0; i<size;i++){
        temp[i]=ReadAccountEntry(i);
    }
    this->CloseConnection();
    return temp;
}

void BankDb::UpdateDatabase(std::vector<Account> NewAccounts){
    fileRemove(this->FileName.c_str());
    for( Account acc: NewAccounts){
        this->AddEntry(acc);
    }
}

void BankDb::DeleteEntryByIndex(int index){
    std::vector<Account> v=this->GetAllEntries();
    verifyValidIndex(index,v.size());
    v.erase(v.begin()+index);
    this->UpdateDatabase(v);
}

void BankDb::UpdateEntry(Account NewClient, int index){
    std::vector<Account> v=this->GetAllEntries();
    verifyValidIndex(index,v.size());
    v[index]=NewClient;
    this->UpdateDatabase(v);
    return;
}

void verifyValidIndex(int index, int size){
    if(index>size){
        throw std::out_of_range("Invalid Index.\n");
    }
}

BankDb::~BankDb()
{
}

#endif