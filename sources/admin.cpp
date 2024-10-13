#include "../admin.h"
#include "../course.h"
#include "../utils.h"
#include <iostream>

using namespace std;

// Constructor
Admin::Admin() {}

void Admin::create_course()
{
    string name, days;
    int min_credits, max_credits, start_time;

    cout << "Enter course name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter minimum credits: ";
    min_credits = numericalInput();

    cout << "Enter maximum credits: ";
    max_credits = numericalInput();

    cout << "Enter start time (24-hour format): ";
    start_time - numericalInput();

    cout << "Enter days (e.g. MWF): ";
    cin >> days;

    if(max_credits < min_credits)
    {
        cout << "Max credits can't be smaller than min credits.";
        returnToMenu();
        return;
    }

    courseBuilder()
        .with_name(name)
        .with_min_credits(min_credits)
        .with_max_credits(max_credits)
        .with_start_time(start_time)
        .with_days(days)
        .finish();

    cout << "Course created successfully!" << endl;
    returnToMenu();
    return;
}

void Admin::list_courses()
{
    for (const auto &course : list_of_courses)
    {
        course.print_in_list();
    }
    returnToMenu();
    return;
}
