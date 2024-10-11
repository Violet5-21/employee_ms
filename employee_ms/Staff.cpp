//
// Created by Violet on 24-10-8.
//

#include "Staff.h"

Staff::Staff(int id, int department_id, string name)
{
    m_id = id;
    m_department_id = department_id;
    m_name = std::move(name);
}

void Staff::show_information()
{
    cout << " Staff id: " << m_id;
    cout << " \tdepartment: " << m_department_id;
    cout << " \tname: " << m_name;
    cout << " \tjob: complete assignments from managers. \n";
}

string Staff::get_department_id()
{
    return {"Staff"};
}
