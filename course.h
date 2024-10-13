#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include <vector>

class Course {
public:
    std::string name;
    int min_credits;
    int max_credits;
    int start_time;
    std::string days;

    Course(std::string n, int min, int max, int start, std::string d);
    void print(int credits) const;       // Mark as const
    void print_in_list() const;          // Mark as const
    bool check_range(int c) const;       // Mark as const
};

// Course Builder to simplify course creation
class courseBuilder {
private:
    std::string name;
    int min_credits;
    int max_credits;
    int start_time;
    std::string days;

public:
    courseBuilder& with_name(std::string n);
    courseBuilder& with_min_credits(int c);
    courseBuilder& with_max_credits(int c);
    courseBuilder& with_start_time(int c);
    courseBuilder& with_days(std::string d);
    void finish();
};

extern std::vector<Course> list_of_courses;

#endif
