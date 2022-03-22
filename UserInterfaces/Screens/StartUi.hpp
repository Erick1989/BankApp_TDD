#ifndef START_UI_HPP
#define START_UI_HPP

#include "../UserInterface.hpp"

class StartUi : public UserInterface
{
public:
    UserInterface * Exec();
protected:
private:
    StartUi::MenuValues CollectChoice();
    UserInterface * GetScreenAddress(StartUi::MenuValues UserChoice);
};

#endif