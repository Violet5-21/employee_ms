#include "Employee.h"

int main()
{
    Employee employee;
    int choice = 0;

    Employee::show_menu();
    cout << "PLease enter an int number(0-7): ";
    while (cin >> choice)
    {
        switch(choice)
        {
            case 0:
                Employee::exit_system();
                break;
            case 1:
                employee.add_employ();
                break;
            case 2:
                employee.show_employee();
                break;
            case 3:
                employee.delete_employee();
                break;
            case 4:
                employee.change_employee();
                break;
            case 5:
                employee.find_employee();
                break;
            case 6:
                employee.sort_employee();
                break;
            case 7:
                employee.delete_all();
                break;
            default:
                cout << "Please enter a right number! \n";
                break;
        }
    }

    return 0;
}
