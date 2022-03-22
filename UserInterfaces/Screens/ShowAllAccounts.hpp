#ifndef SHOW_ALL_ACCOUNTS_HPP
#define SHOW_ALL_ACCOUNTS_HPP

#include "../UserInterface.hpp"

class ShowAllAcc: public UserInterface
{
public:
 UserInterface *  Exec();
 std::vector<Account> GetAllClients();
};


#endif