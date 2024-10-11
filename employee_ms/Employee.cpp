//
// Created by Violet on 24-10-7.
//

#include "Employee.h"

Employee::Employee()
{
    char ch;
    ifstream ifs;
    ifs.open(FILENAME, ios_base::in);
    if (!ifs.is_open() || (ifs >> ch && ifs.eof()))
    {
        cout << "file is not exit. \n";
        m_employee_number = 0;
        m_employee_ptr_arr = nullptr;
        m_file_is_empty = true;
        ifs.close();
    }
    else
    {
        m_employee_number = get_employee_number();
        cout << "the number of employees is " << m_employee_number <<". \n";
        m_employee_ptr_arr = new Worker * [m_employee_number];
        initialize_employee();
        for (int i = 0; i < m_employee_number; ++i)
        {
            cout << "id: " << m_employee_ptr_arr[i]->m_id
                << " department_id: " << m_employee_ptr_arr[i]->m_department_id
                << " name: " << m_employee_ptr_arr[i]->m_name << endl;
        }
    }
}

void Employee::show_menu()
{
    string star1(65, '*');
    string star2(12, '*');

    cout << star1 << endl;
    cout << star2 << " Welcome to employee management system!  " << star2 << endl;
    cout << star2 << "    1. Add employees' information      " << star2 << endl;
    cout << star2 << "    2. Show employees' information       " << star2 << endl;
    cout << star2 << "    3. Delete a employee's information   " << star2 << endl;
    cout << star2 << "    4. Change a employee's information   " << star2 << endl;
    cout << star2 << "    5. Find a employee's information     " << star2 << endl;
    cout << star2 << "    6. Sort employees according to IDs   " << star2 << endl;
    cout << star2 << "    7. Delete all employees              " << star2 << endl;
    cout << star2 << "    0. Exit employee management system   " << star2 << endl;
    cout << star1  << endl;
}

void Employee::exit_system()
{
    cout << "Good bye! ";
    exit(0);
}

void Employee::add_employ()
{
    cout << "Please enter the number of employees you want to add: ";
    int add_number = 0;
    if (cin >> add_number && add_number > 0)
    {
        int new_size = m_employee_number + add_number;
        auto new_space = new Worker * [new_size];

        if (m_employee_number > 0)
        {
            for (int i = 0; i < m_employee_number; ++i)
            {
                new_space[i] = m_employee_ptr_arr[i];
            }
        }
        for (int i = 0; i < add_number; ++i)
        {
            int id, department_id;
            string name;

            cout << "Please enter the id of the employee of " << i+1 << ": ";
            cin >> id;
            cout << "Please enter the name of the employee of " << i+1 << ": ";
            cin >> name;
            cout << "1.Staff\n";
            cout << "2.Manager\n";
            cout << "3.Boss\n";
            cout << "Please enter the department id of " << i+1 <<": ";
            cin >> department_id;

            Worker * worker = nullptr;
            switch (department_id)
            {
                case 1:
                    worker = new Staff(id, 1, name);
                    break;
                case 2:
                    worker = new Manager(id, 2, name);
                    break;
                case 3:
                    worker = new Boss(id, 3, name);
                    break;
                default:
                    cout << "Please enter a correct department id. \n";
                    break;
            }
            new_space[m_employee_number+i] = worker;
        }
        delete [] m_employee_ptr_arr;
        m_employee_ptr_arr = new_space;
        m_employee_number = new_size;
        m_file_is_empty = false;
        cout << "Adding completed! \n";
        save();
    }
    else
    {
        cout << "Bad number! \n";
    }
}

void Employee::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios_base::out);
    for (int i = 0; i < m_employee_number; ++i)
    {
        ofs << m_employee_ptr_arr[i]->m_id << " "
            << m_employee_ptr_arr[i]->m_department_id << " "
            << m_employee_ptr_arr[i]->m_name << endl;
    }
    ofs.close();
}

int Employee::get_employee_number()
{
    ifstream ifs;
    ifs.open(FILENAME, ios_base::in);
    int id;
    int department_id;
    string name;
    int number = 0;
    while (ifs >> id && ifs >> department_id && ifs >> name)
    {
        ++number;
    }
    ifs.close();

    return number;
}

void Employee::initialize_employee()
{
    ifstream ifs;
    ifs.open(FILENAME, ios_base::in);
    int id;
    int department_id;
    string name;
    int i = 0;
    while (ifs >> id && ifs >> department_id && ifs >> name)
    {
        Worker * worker = nullptr;
        if (department_id == 1)
            worker = new Staff(id, department_id, name);
        else if (department_id == 2)
            worker = new Manager(id, department_id, name);
        else
            worker = new Boss(id, department_id, name);
        m_employee_ptr_arr[i] = worker;
        ++i;
    }
}

void Employee::show_employee()
{
    if (m_file_is_empty)
        cout << "File is empty or not exist. \n";
    else
    {
        for (int i = 0; i < m_employee_number; ++i)
        {
            m_employee_ptr_arr[i]->show_information();
        }
    }
}

int Employee::is_exist(int id)
{
    int flag = -1;

    for (int i = 0; i < m_employee_number; ++i)
        if (m_employee_ptr_arr[i]->m_id == id)
            flag = i;
    return flag;
}

void Employee::delete_employee()
{
    if (m_file_is_empty)
        cout << "File is empty or not exist. " << endl;
    else
    {
        cout << "Please enter the id of the employee you want to delete: ";
        int id = 0;
        cin >> id;
        int flag = is_exist(id);

        if (flag == -1)
            cout << "Employee not found. \n";
        else
        {
            for (int i = flag; i < m_employee_number; ++i)
                m_employee_ptr_arr[i] = m_employee_ptr_arr[i+1];
            --m_employee_number;
            save();
            cout << "Employee deleted. \n";
        }
    }
}

void Employee::change_employee()
{
    if (m_file_is_empty)
        cout << "File is empty or not exist. " << endl;
    cout << "Please enter the id of the employee you want to delete: ";
    int id = 0;
    cin >> id;
    int flag = is_exist(id);

    if (flag == -1)
        cout << "Employee not found. \n";
    else
    {
        delete m_employee_ptr_arr[flag];

        int new_id = 0;
        int new_department_id = 0;
        string new_name;

        cout << "Employee found. \nPlease enter a new id: ";
        cin >> new_id;
        cout << "Please enter a new name: ";
        cin >> new_name;
        cout << "1.Staff\n";
        cout << "2.Manager\n";
        cout << "3.Boss\n";
        cout << "Please enter a new department id: ";
        cin >> new_department_id;

        Worker * worker = nullptr;
        switch (new_department_id)
        {
            case 1:
                worker = new Staff(new_id, 1, new_name);
                break;
            case 2:
                worker = new Manager(new_id, 2, new_name);
                break;
            case 3:
                worker = new Boss(new_id, 3, new_name);
                break;
            default:
                cout << "Please enter a new correct department id. \n";
                break;
        }
        m_employee_ptr_arr[flag] = worker;
        cout << "employee changed. \n";
        save();
    }
}

void Employee::find_employee()
{
    if (m_file_is_empty)
        cout << "File is empty or not exist. " << endl;
    else
    {
        cout << "1. find an employee by id. \n";
        cout << "2. find an employee by name. \n";
        cout << "please enter the way you want to find a employee: ";
        int select = 0;
        cin >> select;

        if (select == 1)
        {
            cout << "Please enter the employee's id: ";
            int id;
            cin >> id;

            int mark = is_exist(id);
            if (mark == -1)
                cout << "The employee is not exist. \n";
            else {
                cout << "found. \n";
                m_employee_ptr_arr[mark]->show_information();
            }
        }
        else if (select == 2)
        {
            cout << "please enter the employee's name: ";
            string name;
            cin >> name;

            bool mark = false;
            for (int i = 0; i < m_employee_number; ++i) {
                if (m_employee_ptr_arr[i]->m_name == name) {
                    mark = true;
                    cout << "found. \n";
                    m_employee_ptr_arr[i]->show_information();
                }
            }
            if (mark)
                cout << "The employee is not exist. \n";
        }
        else
            cout << "Please enter a correct number. \n";
    }
}

void Employee::sort_employee()
{
    if (m_file_is_empty)
        cout << "File is empty or not exist. " << endl;
    else
    {
        cout << "1. sort by ids from small to large. \n";
        cout << "2. sort by ids from large to small. \n";
        cout << "please select the way you want to sort: ";
        int select = 0;
        cin >> select;

        auto signal
        = [select](Worker * a, Worker * b) { return (select == 1) ? (a->m_id > b->m_id) : (a->m_id < b->m_id); };
        if (select != 1 && select != 2)
            cout << "please enter a correct number. \n";
        else
        {
            for (int i = 0; i < m_employee_number - 1; ++i)
            {
                for (int j = 0; j < m_employee_number - i - 1; ++j)
                {
                    if (signal(m_employee_ptr_arr[j], m_employee_ptr_arr[j + 1]))
                    {
                        Worker *temp = m_employee_ptr_arr[j];
                        m_employee_ptr_arr[j] = m_employee_ptr_arr[j + 1];
                        m_employee_ptr_arr[j + 1] = temp;
                    }
                }
            }
        }
        cout << "sorted. \n";
        save();
    }
}

void Employee::delete_all()
{
    if (m_file_is_empty)
        cout << "File is already empty. \n";
    else
    {
        cout << "1. confirmed. \n";
        cout << "2. back. \n";
        cout << "are you sure: ";
        int select = 0;
        cin >> select;

        if (select == 1)
        {
            ofstream ofs;
            ofs.open(FILENAME, ios_base::trunc);
            ofs.close();

            for (int i = 0; i < m_employee_number; ++i)
                delete m_employee_ptr_arr[i];
            m_employee_number = 0;
            delete [] m_employee_ptr_arr;
            m_employee_ptr_arr = nullptr;
            m_file_is_empty = true;

            cout << "deleted. \n";
        }
        else if (select == 2)
            cout << "delete canceled. \n";
        else
            cout << "please enter a correct number. \n";
    }
}
