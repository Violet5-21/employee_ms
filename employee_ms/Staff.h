//
// Created by Violet on 24-10-8.
//

#ifndef EMPLOYEE_MS_STAFF_H
#define EMPLOYEE_MS_STAFF_H

#include <utility>
#include "Worker.h"

using std::cout;

class Staff : public Worker
{
public:
    Staff(int id, int department_id, string name);
    void show_information() override;
    string get_department_id() override;
};

#endif //EMPLOYEE_MS_STAFF_H
