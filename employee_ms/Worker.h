//
// Created by Violet on 24-10-8.
//

#ifndef EMPLOYEE_MS_WORKER_H
#define EMPLOYEE_MS_WORKER_H

#include <iostream>
#include <string>

using std::string;

class Worker
{
public:
    int m_id;
    string m_name;
    int m_department_id;
    virtual void show_information() = 0;
    virtual string get_department_id() = 0;
    virtual ~Worker() = default;
};

#endif //EMPLOYEE_MS_WORKER_H
