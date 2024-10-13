#ifndef STUDENT_H
#define STUDENT_H

#include <set>
#include <vector>

class Student {
private:
    int credits;

public:
    std::set<int> courses;

    Student();
    void add_course(int course_id, int credit);  // Add course to student's schedule
    void remove_course(int course_id);           // Remove course from student's schedule
    void print_schedule();                       // Print student's current schedule
    bool has_conflict(int start_time, const std::string& days); // Check for schedule conflicts
};

#endif
