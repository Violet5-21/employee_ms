//
// Created by Violet on 24-10-8.
//

#include "Boss.h"

Boss::Boss(int id, int department_id, string name)
{
    m_id = id;
    m_department_id = department_id;
    m_name = std::move(name);
}

void Boss::show_information()
{
    cout << " Boss id: " << m_id;
    cout << " \tdepartment: " << m_department_id;
    cout << " \tname: " << m_name;
    cout << " \tjob: govern all affairs. \n";
}

string Boss::get_department_id()
{
    return {"Boss"};
}
