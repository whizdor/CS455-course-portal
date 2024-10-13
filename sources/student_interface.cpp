#include "../student_interface.h"
#include "../student.h"
#include "../course.h"
#include "../utils.h"
#include <iostream>

using namespace std;

Student student;

StudentInterface::StudentInterface() {}

void StudentInterface::showMenu()
{
    cout << "1. Add Course\n";
    cout << "2. View Schedule\n";
    cout << "0. Exit\n";
    maxChoices = 3;
}

bool StudentInterface::exitCondition()
{
    clearScreen();
    return currentChoice == 0;
}

void StudentInterface::executeChoice()
{
    if (currentChoice == 1)
    {
        add_course();
    }
    else if (currentChoice == 2)
    {
        student.print_schedule();
    }
    return;
}

void StudentInterface::add_course()
{
    cout << "Available Courses: \n";
    for (size_t i = 0; i < list_of_courses.size(); ++i)
    {
        cout << i << ". ";
        list_of_courses[i].print_in_list(); 
    }

    int course_id, credits;
    cout << "Enter course ID: ";
    course_id = numericalInput();
    cout << "Enter credits: ";
    credits = numericalInput();

    student.add_course(course_id, credits);
    return;
}
