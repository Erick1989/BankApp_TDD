#ifndef WITHDRAWAL_HPP
#define WITHDRAWAL_HPP

#include "../UserInterface.hpp"
class Withdrawal: public UserInterface
{
public:
 UserInterface * Exec();
 void WithdrawalFromAcc(int accountIndex,float WithdrawalValue);
private:
};


#endif