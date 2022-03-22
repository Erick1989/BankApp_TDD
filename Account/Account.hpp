#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>
#include <stdexcept>
#include<iostream>
#include <iomanip>

class Account{
    private:
    std::string Owner;
    float balance;
    int ClientId;
    friend class BankDb;
    Account(std::string Owner, float InitialBalance,int Id);
    

    public:
    Account(std::string Owner, float InitialBalance);
    void deposit(float ammount);
    float getBalance();
    int getId();
    std::string getOwner();
    void withdrawal(float ammount);
    std::string CreateStream();
    std::string ConvertBalanceToStr();
    friend void ResetIdCounter();
    bool operator ==(const Account& Acc);
    

    protected:
    void verifyAmmount(float ammount);
    static int idCounter;
    
    
};
void ResetIdCounter();


#endif