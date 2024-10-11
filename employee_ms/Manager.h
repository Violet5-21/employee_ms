//
// Created by Violet on 24-10-8.
//

#ifndef EMPLOYEE_MS_MANAGER_H
#define EMPLOYEE_MS_MANAGER_H

#include <utility>
#include "Worker.h"

using std::cout;

class Manager : public Worker
{
public:
    Manager(int id, int department_id, string name);
    void show_information() override;
    string get_department_id() override;
};

#endif //EMPLOYEE_MS_MANAGER_H
