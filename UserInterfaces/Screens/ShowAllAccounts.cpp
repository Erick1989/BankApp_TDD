#ifndef SHOW_ALL_ACCOUNTS_CPP
#define SHOW_ALL_ACCOUNTS_CPP

#include "ShowAllAccounts.hpp"

UserInterface * ShowAllAcc::Exec(){
    std::cout<<"***Show All Accounts***\n";
    std::vector<Account> AllEntries = this->GetAllClients();
    std::vector<Account>::iterator it;
    for(it=AllEntries.begin();it!=AllEntries.end();it++)
    {
        std::cout<< it->CreateStream()<<"\n";
    }
    return this->Baseaddr[0];
}

std::vector<Account> ShowAllAcc::GetAllClients(){
    return this->DatabaseLink->GetAllEntries();
}

#endif