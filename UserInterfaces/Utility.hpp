#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <string>
#include <iostream>

void ErrorMessage(const char * ErrorMsg);
void VerifyValidChars(std::string &NameString);
void VerifyEmpty(std::string &NameString);

#endif