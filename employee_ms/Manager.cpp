//
// Created by Violet on 24-10-8.
//

#include "Manager.h"

Manager::Manager(int id, int department_id, string name)
{
    m_id = id;
    m_department_id = department_id;
    m_name = std::move(name);
}

void Manager::show_information()
{
    cout << " Manager id: " << m_id;
    cout << " \tdepartment: " << m_department_id;
    cout << " \tname: " << m_name;
    cout << " \tjob: complete assignments from bosses, assign jobs to workers. \n";
}

string Manager::get_department_id()
{
    return {"Manager"};
}
