#ifndef DEPOSIT_HPP
#define DEPOSIT_HPP

#include "../UserInterface.hpp"

class Deposit: public UserInterface
{
public:
 UserInterface * Exec();
 void DepositIntoAcc(int accountIndex,float DepositValue);
private:
};

#endif