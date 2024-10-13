#include "../utils.h"
#include <iostream>

using namespace std;

void printLineDivider() 
{
    cout << string(70, '-') << endl;
    return;
}

void clearScreen()
{
    cout << "\033[2J\033[1;1H";
    return;
}

void returnToMenu()
{
    cout << "Press Enter to continue.";
    fgetc(stdin);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return;
}

int numericalInput()
{
    int temp;
    while(! (cin >> temp))
    {
        cin.clear();
        cin.ignore();
        cout << "Incorrect entry. Try again: ";
    }
    return temp;
}