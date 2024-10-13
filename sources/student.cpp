#include "../student.h"
#include "../course.h"
#include "../utils.h"
#include <iostream>

using namespace std;

Student::Student()
{
    credits = 0;
}

void Student::add_course(int course_id, int credit)
{
    if (course_id >= 0 && course_id < list_of_courses.size())
    {
        if (!has_conflict(list_of_courses[course_id].start_time, list_of_courses[course_id].days))
        {
            courses.insert(course_id);
            credits += credit;
            std::cout << "Course added successfully.\n";
        }
        else
        {
            std::cout << "Error: This course conflicts with your current schedule.\n";
        }
    }
    else
    {
        std::cout << "Invalid course ID.\n";
    }
    returnToMenu();
    return;
}

void Student::print_schedule()
{
    if (courses.empty())
    {
        std::cout << "You have no courses enrolled.\n";
    }
    else
    {
        std::cout << "Your current schedule: \n";
        for (auto course_id : courses)
        {
            std::cout << course_id << ". ";
            list_of_courses[course_id].print(credits);
        }
    }
    returnToMenu();
    return;
}

bool Student::has_conflict(int start_time, const std::string &days)
{
    for (auto course_id : courses)
    {
        if (list_of_courses[course_id].start_time == start_time)
        {
            return true;
        }
    }
    return false;
}
