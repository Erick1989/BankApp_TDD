#ifndef OPEN_ACCOUNT_HPP
#define OPEN_ACCOUNT_HPP

#include "../UserInterface.hpp"

class OpenAccount : public UserInterface
{
public:
    UserInterface * Exec();
    void CollectName(std::string &NameString);
    void SaveAccountInDb(Account NewAccount);
protected:
private:
};

#endif