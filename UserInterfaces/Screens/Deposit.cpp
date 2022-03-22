#ifndef DEPOSIT_CPP
#define DEPOSIT_CPP

#include "Deposit.hpp"
#include "../Utility.hpp"

UserInterface * Deposit::Exec(){
    std::cout<<"***Deposit***\n";
    float DepositValue=0; int AccIndex=-1;
    std::cout<<"Enter Account Number:";
    try{
        AccIndex=this->CollectAccountNumber();
    }
    catch(std::invalid_argument const& ex){
        ErrorMessage("Invalid account number\n");
        return this->Baseaddr[0];
    }
    std::cout<<"Enter Deposit Ammount:";
    try{
        DepositValue= this->CollectValue();
    }
    catch(std::invalid_argument const& ex){
        ErrorMessage("Invalid deposit value\n");
        return this->Baseaddr[0];
    }
    try{
        this->DepositIntoAcc(AccIndex,DepositValue);
    }
    catch(std::out_of_range const& ex){
        ErrorMessage(ex.what());
        return this->Baseaddr[0];
    }
    std::cout<<"\nAmount "<< DepositValue<<" is Deposited"<<std::endl;
    return this->Baseaddr[0];
}

void Deposit::DepositIntoAcc(int accountIndex,float DepositValue){
    Account temp= this->DatabaseLink->GetDbEntryByIndex(accountIndex);
    temp.deposit(DepositValue);
    this->DatabaseLink->UpdateEntry(temp,accountIndex);
    return;
}
#endif