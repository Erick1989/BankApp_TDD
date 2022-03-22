#ifndef USER_INTERFACE_HPP
#define USER_INTERFACE_HPP
#include <string>
#include <iostream>
#include "../Database/BankDatabase.hpp"

class UserInterface
{
public:
    enum MenuValues
    {
        Start,
        Open_Account,
        Balance_Enquire,
        Deposit,
        Withdrawal,
        Close_Account,
        Show_All_Accounts,
        Quit
    };

    virtual UserInterface * Exec(){
        return nullptr ;
    }
    void setDatabaseLink(BankDb * DatabaseLink);
    void setUiBaseAddr(UserInterface * * _Baseaddr);

    protected:
    static UserInterface * * Baseaddr;
    static BankDb * DatabaseLink;
    int CollectAccountNumber();
    float  CollectValue();
};


#endif