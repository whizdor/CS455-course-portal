#include "../admin_interface.h"
#include "../admin.h"
#include "../utils.h"
#include <iostream>

using namespace std;

Admin admin;

AdminInterface::AdminInterface() {}

void AdminInterface::showMenu()
{
    cout << "1. Create Course" << endl;
    cout << "2. List Courses" << endl;
    cout << "0. Exit" << endl;
    maxChoices = 2;
    return;
}

bool AdminInterface::exitCondition()
{
    clearScreen();
    return currentChoice == 0;
}

void AdminInterface::executeChoice()
{
    if (currentChoice == 1)
    {
        admin.create_course();
    }
    else if (currentChoice == 2)
    {
        admin.list_courses();
    }
    return;
}
