#include "../interface.h"
#include "../utils.h"
#include "../admin_interface.h"
#include "../student_interface.h"
#include <iostream>

using namespace std;

// Constructor
Interface::Interface() : currentChoice(0), maxChoices(0) {}

// Destructor
Interface::~Interface() {}

void Interface::run()
{
    while (true)
    {
        welcomeScreen();
        showMenu();
        printLineDivider();
        getChoice();
        if (exitCondition())
        {
            break;
        }
        executeChoice();
    }
    return;
}

void Interface::welcomeScreen()
{
    clearScreen();
    printLineDivider();
    cout << "Welcome to the Course Management System!" << endl;
    printLineDivider();
    return;
}

void Interface::getChoice()
{
    cout << "Enter your choice: ";
    currentChoice = numericalInput();
    while(currentChoice < 0 || currentChoice > maxChoices)
    {
        cout << "Invalid choice! Please enter one from the displayed list: ";
        currentChoice = numericalInput();
    }
    return;
}

bool Interface::exitCondition()
{
    clearScreen();
    cout << "Exiting the system... Goodbye!" << endl;
    return currentChoice == 0;
}

void Interface::showMenu()
{
    cout << "Chose one privilege level-" << endl;
    cout << "1. Administrator" << endl;
    cout << "2. Student" << endl;
    cout << "0. Exit" << endl;
    maxChoices = 2;
    return;
}

void Interface::executeChoice()
{
    if (currentChoice == 1)
    {
        clearScreen();
        AdminInterface adminInterface;
        adminInterface.run();
    }
    else if (currentChoice == 2)
    {
        clearScreen();
        StudentInterface studentInterface;
        studentInterface.run();
    }
    else
    {
        cout << "Invalid choice! Please enter one from the displayed list." << endl;
        returnToMenu();
    }
    return;
}
