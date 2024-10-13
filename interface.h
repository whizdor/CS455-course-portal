#ifndef INTERFACE_H
#define INTERFACE_H

class Interface
{
protected:
    int currentChoice;
    int maxChoices;

public:
    Interface();
    virtual ~Interface();

    void welcomeScreen();
    void chooseCategory();

    virtual void run();
    virtual void showMenu();
    virtual void getChoice();
    virtual bool exitCondition();
    virtual void executeChoice();
};

#endif
