#ifndef USER_INTERFACE_CPP
#define USER_INTERFACE_CPP

#include "UserInterface.hpp"
#include "Utility.hpp"

BankDb * UserInterface::DatabaseLink;
UserInterface * * UserInterface::Baseaddr;

void UserInterface::setDatabaseLink(BankDb * DatabaseLink){
    this->DatabaseLink=DatabaseLink;
    return;
}

void UserInterface::setUiBaseAddr(UserInterface * * _Baseaddr){
    this->Baseaddr=_Baseaddr;
}

float  UserInterface::CollectValue(){
    std::string Val;
    std::cin>>Val;
    int retval=-1;
    retval= std::stof(Val);
    return retval;
}

int UserInterface::CollectAccountNumber(){
    std::string AccNumber;
    std::cin>>AccNumber;
    int retval=-1;
    retval=std::stoi(AccNumber);
    return retval;
}

#endif