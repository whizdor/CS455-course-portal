#ifndef STUDENT_INTERFACE_H
#define STUDENT_INTERFACE_H

#include "interface.h"

class StudentInterface : public Interface {
public:
    StudentInterface();

    bool exitCondition() override;
    void showMenu() override;
    void executeChoice() override;
    void add_course();
};

#endif
