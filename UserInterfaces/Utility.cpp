#ifndef UTILITY_CPP
#define UTILITY_CPP

#include "Utility.hpp"

void ErrorMessage(const char * ErrorMsg){
    std::cout << "Error:" << ErrorMsg;
    std::cout << "Reset to inital screen"<< '\n';
}

void VerifyValidChars(std::string &NameString){
    std::string::iterator it;
    for(it=NameString.begin();it!=NameString.end();it++){
       if(*it<'A' || (*it>'Z' && *it<'a') || *it>'z' )
            throw std::invalid_argument("Name contains invalid characters");
    }
}

void VerifyEmpty(std::string &NameString){
    if(NameString.empty())
            throw std::invalid_argument("Name is Empty");
}


#endif