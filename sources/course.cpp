#include "../course.h"
#include <vector>

using namespace std;

vector<Course> list_of_courses;

Course::Course(string n, int min, int max, int start, string d)
{
    name = n;
    min_credits = min;
    max_credits = max;
    start_time = start;
    days = d;
}

void Course::print(int credits) const
{
    cout << name << " for " << credits << " credits, from " << start_time << ":00 hrs to " << start_time + 1 << ":00 hrs on ";
    for (auto d : days)
    {
        cout << d << " ";
    }
    cout << endl;
    return;
}

void Course::print_in_list() const
{
    cout << name << " Credits: [" << min_credits << ", " << max_credits << "]" << endl;
    return;
}

bool Course::check_range(int c) const
{
    return c >= min_credits && c <= max_credits;
}

courseBuilder &courseBuilder::with_name(string n)
{
    name = n;
    return *this;
}

courseBuilder &courseBuilder::with_min_credits(int c)
{
    min_credits = c;
    return *this;
}

courseBuilder &courseBuilder::with_max_credits(int c)
{
    max_credits = c;
    return *this;
}

courseBuilder &courseBuilder::with_start_time(int c)
{
    start_time = c;
    return *this;
}

courseBuilder &courseBuilder::with_days(string d)
{
    days = d;
    return *this;
}

void courseBuilder::finish()
{
    Course(name, min_credits, max_credits, start_time, days);
    list_of_courses.push_back(Course(name, min_credits, max_credits, start_time, days));
}
