#ifndef CLOSE_ACCOUNT_HPP
#define CLOSE_ACCOUNT_HPP

#include "../UserInterface.hpp"

class CloseAccount: public UserInterface
{
public:
 UserInterface *  Exec();
 void CloseAccountByIndex(int index);
private:
};
#endif