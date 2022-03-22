#ifndef START_UI_CPP
#define START_UI_CPP

#include "StartUi.hpp"

UserInterface * StartUi::Exec()
{
    std::cout<<"***Banking System***"<<std::endl;
    std::cout << "\n\tSelect one option below ";
    std::cout << "\n\t1 Open an Account";
    std::cout << "\n\t2 Balance Enquiry";
    std::cout << "\n\t3 Deposit";
    std::cout << "\n\t4 Withdrawal";
    std::cout << "\n\t5 Close an Account";
    std::cout << "\n\t6 Show All Accounts";
    std::cout << "\n\t7 Quit";
    std::cout << "\nEnter your choice: ";
    StartUi::MenuValues UserChoice = this->CollectChoice();
    return this->GetScreenAddress(UserChoice);
}

UserInterface * StartUi::GetScreenAddress(StartUi::MenuValues UserChoice){
    UserInterface * Add= nullptr;
    switch(UserChoice){
        case(StartUi::MenuValues::Open_Account):
        Add= this->Baseaddr[1];
        break;
        case(StartUi::MenuValues::Balance_Enquire):
        Add= this->Baseaddr[2];
        break;
        case(StartUi::MenuValues::Deposit):
        Add= this->Baseaddr[3];
        break;
        case(StartUi::MenuValues::Withdrawal):
        Add= this->Baseaddr[4];
        break;
        case(StartUi::MenuValues::Close_Account):
        Add= this->Baseaddr[5];
        break;
        case(StartUi::MenuValues::Show_All_Accounts):
        Add= this->Baseaddr[6];
        break;
        case(StartUi::MenuValues::Quit): Add= nullptr;break;
        default:Add= this->Baseaddr[0]; break;
    }
    return Add;

}

StartUi::MenuValues StartUi::CollectChoice()
{
    StartUi::MenuValues UserChoice;
    int var;
    std::cin >> var;
    switch (var)
    {
    case 1:
        UserChoice = StartUi::MenuValues::Open_Account;
        break;
    case 2:
        UserChoice = StartUi::MenuValues::Balance_Enquire;
        std::cout<<"Option Balance_Enquire Selected\n";
        break;
    case 3:
        UserChoice = StartUi::MenuValues::Deposit;
        std::cout<<"Option Deposit Selected\n";
        break;
    case 4:
        UserChoice = StartUi::MenuValues::Withdrawal;
        std::cout<<"Option Withdrawal Selected\n";
        break;
    case 5:
        UserChoice = StartUi::MenuValues::Close_Account;
        std::cout<<"Option Close_Account Selected\n";
        break;
    case 6:
        UserChoice = StartUi::MenuValues::Show_All_Accounts;
        std::cout<<"Option Show_All_Accounts Selected\n";
        break;
    case 7:
        UserChoice = StartUi::MenuValues::Quit;
        std::cout<<"Option Quit Selected\n";
        break;
    default:
        std::cout<<"Invalid Option\nReturn to Start Menu.\n";
        UserChoice = StartUi::MenuValues::Start;
        break;
    }
    return UserChoice;
}

#endif