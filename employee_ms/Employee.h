//
// Created by Violet on 24-10-7.
//

#ifndef EMPLOYEE_MS_1_H
#define EMPLOYEE_MS_1_H

#define FILENAME "employee_file.txt"

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "Worker.h"
#include "Staff.h"
#include "Manager.h"
#include "Boss.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ios_base;

class Employee
{
private:
    int m_employee_number;
    Worker ** m_employee_ptr_arr;
    bool m_file_is_empty;
public:
    Employee();
    static void show_menu();
    static void exit_system();
    void add_employ();
    void save();
    static int get_employee_number();
    void initialize_employee();
    void show_employee();
    int is_exist(int id);
    void delete_employee();
    void change_employee();
    void find_employee();
    void sort_employee();
    void delete_all();
    ~Employee() = default;
};

#endif //EMPLOYEE_MS_1_H
