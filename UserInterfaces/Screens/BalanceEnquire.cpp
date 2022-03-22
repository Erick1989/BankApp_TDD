#ifndef BALANCE_ENQUIRE_CPP
#define BALANCE_ENQUIRE_CPP

#include "BalanceEnquire.hpp"
#include "../Utility.hpp"

UserInterface * BalanceEnquire::Exec(){
    int index=-1;
    std::cout<<"***BalanceEnquire***\n";
    std::cout<<"Enter Account Number:";
    try{
        index=this->CollectAccountNumber();
    }
    catch(std::invalid_argument const& ex){
        ErrorMessage("Invalid account number\n");
        return this->Baseaddr[0];
    }
    try{
        Account Acc=this->CollectAccountByIndex(index);
        std::cout<<"Your Account Details\n";
        std::cout<<Acc.CreateStream()<<"\n";
    }
    catch(std::out_of_range const& ex){
        ErrorMessage(ex.what());
    }
    return this->Baseaddr[0];
}

Account BalanceEnquire::CollectAccountByIndex(int AccountIndex){
    return this->DatabaseLink->GetDbEntryByIndex(AccountIndex);
}

#endif