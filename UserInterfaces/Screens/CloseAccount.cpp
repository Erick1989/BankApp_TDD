#ifndef CLOSE_ACCOUNT_CPP
#define CLOSE_ACCOUNT_CPP

#include "CloseAccount.hpp"
#include "../Utility.hpp"

UserInterface * CloseAccount::Exec(){
    int index=-1;
    std::cout<<"***Close Account***\n";
    std::cout<<"Enter Account Number:";
    try{
        index=this->CollectAccountNumber();
    }
    catch(std::invalid_argument const& ex){
        ErrorMessage("Invalid account number\n");
        return this->Baseaddr[0];
    }
    try{
        this->CloseAccountByIndex(index);
    }
    catch(std::invalid_argument const& ex){
        ErrorMessage("Invalid account number\n");
        return this->Baseaddr[0];
    }
    std::cout<<std::endl<<"Account is Closed\n"<<std::endl;
    return this->Baseaddr[0];
}

void CloseAccount::CloseAccountByIndex(int index){
    this->DatabaseLink->DeleteEntryByIndex(index);
    return;
}

#endif