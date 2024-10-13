#ifndef ADMIN_INTERFACE_H
#define ADMIN_INTERFACE_H

#include "interface.h"

class AdminInterface : public Interface
{
public:
    AdminInterface();
    
    bool exitCondition() override;
    void showMenu() override;
    void executeChoice() override;
};

#endif
