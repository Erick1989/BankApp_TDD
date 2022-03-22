#ifndef BALANCE_ENQUIRE_HPP
#define BALANCE_ENQUIRE_HPP

#include "../UserInterface.hpp"

class BalanceEnquire: public UserInterface
{
public:
 UserInterface * Exec();
 Account CollectAccountByIndex(int AccountIndex);
private:
};

#endif