#ifndef WITHDRAWAL_CPP
#define WITHDRAWAL_CPP
#include "Withdrawal.hpp"
#include "../Utility.hpp"

void Withdrawal::WithdrawalFromAcc(int accountIndex,float WithdrawalValue){
    Account temp= this->DatabaseLink->GetDbEntryByIndex(accountIndex);
    temp.withdrawal(WithdrawalValue);
    this->DatabaseLink->UpdateEntry(temp,accountIndex);
}

UserInterface *  Withdrawal::Exec(){
    float WithdrawalValue=0; int index;
    std::cout<<"***Withdrawal***\n";
    std::cout<<"Enter Account Number:";
    try{
        index=this->CollectAccountNumber();
    }
    catch(std::invalid_argument const& ex){
        ErrorMessage("Invalid account number\n");
        return this->Baseaddr[0];
    }
    std::cout<<"Enter Withdrawn Ammount:";
    try{
        WithdrawalValue= this->CollectValue();
    }
    catch(std::invalid_argument const& ex){
        ErrorMessage("Invalid Withdrawn value\n");
        return this->Baseaddr[0];
    }
    try{
        this->WithdrawalFromAcc(index,WithdrawalValue);
        std::cout<<"\nAmount "<< WithdrawalValue<<" Withdrawn"<<std::endl;
    }
    catch(std::out_of_range const &ex){
        ErrorMessage(ex.what());
        return this->Baseaddr[0];
    }
    
    return this->Baseaddr[0];
}

#endif