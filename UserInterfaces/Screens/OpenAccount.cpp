#ifndef OPEN_ACCOUNT_CPP
#define OPEN_ACCOUNT_CPP

#include "OpenAccount.hpp"
#include "../Utility.hpp"
#include "../../Account/Account.hpp"
#include "../../Database/BankDatabase.hpp"

UserInterface * OpenAccount::Exec()
{
    std::cout<<"***Open Account***\n";
    std::string FirstName, LastName;
    float InitialBalance;
    try{
        std::cout<<"Enter First Name: ";
        this->CollectName(FirstName);
        std::cout<<"Enter Last Name: ";
        this->CollectName(LastName);
        std::cout<<"Enter initial Balance: ";
        InitialBalance= this->CollectValue();
        Account Acc(FirstName+" " +LastName,InitialBalance);
        this->SaveAccountInDb(Acc);
    }
    catch(std::invalid_argument const& ex){
        ErrorMessage(ex.what());
        return this->Baseaddr[0];
    }
    std::cout<<std::endl<<"Congradulation Account is Created\n"<<std::endl;
    return this->Baseaddr[0];
}

void  OpenAccount::CollectName(std::string &NameString){
    std::cin>>NameString;
    VerifyEmpty(NameString);
    VerifyValidChars(NameString);
}

void OpenAccount::SaveAccountInDb(Account NewAccount){
    this->DatabaseLink->AddEntry(NewAccount);
}



#endif