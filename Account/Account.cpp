#ifndef ACCOUNT_CPP
#define ACCOUNT_CPP

#include "Account.hpp"

int Account::idCounter=0;
void ResetIdCounter(){
    Account::idCounter=0;
}

Account::Account(std::string Owner, float InitialBalance)
{
    this->Owner = Owner;
    if (InitialBalance < 99.99)
    {
        throw std::invalid_argument("The account initial balance must be greater than 99.99€");
    }
    this->balance = InitialBalance;
    this->ClientId= this->idCounter++;    
    return;
}

Account::Account(std::string Owner, float InitialBalance,int Id){
    this->Owner=Owner;
    this->balance = InitialBalance;
    this->ClientId= Id;
}

int Account::getId(){
return this->ClientId;
}

std::string Account::getOwner(){
    return this->Owner;
}

void Account::deposit(float ammount)
{
    this->verifyAmmount(ammount);
    this->balance += ammount;
    return;
}

float Account::getBalance()
{
    return this->balance;
}

std::string Account::CreateStream(){
    std::string temp;

    temp="Account Owner: "+this->Owner+"<\n";
    temp+="Balance: "+this->ConvertBalanceToStr()+"<\n";
    temp+="Client Id: "+std::to_string(this->getId())+"<\n";
    return temp;
}

std::string Account::ConvertBalanceToStr(){
    std::ostringstream streamObj;
    streamObj << std::fixed;
    streamObj << std::setprecision(2);
    streamObj << this->balance;
    if(this->balance>0){
        return   "+"+streamObj.str();
    }
    else{
        return   streamObj.str();
    }
}

void Account::withdrawal(float ammount)
{
    float tempBalance = 0;
    this->verifyAmmount(ammount);
    if (this->balance - ammount <= -1000)
        throw std::invalid_argument("Invalid ammount, balance must be greater than -1000");
    this->balance -= ammount;
    return;
}

void Account::verifyAmmount(float ammount)
{
    if (ammount <= 0)
    {
        throw std::invalid_argument("For Deposits the ammount must be positive");
    }
}

bool Account::operator ==(const Account& Acc){
    if( this->Owner == Acc.Owner & 
        this->balance == Acc.balance &  
        this->ClientId == Acc.ClientId)
        {
        return true;
    }
    return false;
}

#endif