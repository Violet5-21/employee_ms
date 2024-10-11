cmake_minimum_required(VERSION 3.29)
project(employee_ms)

set(CMAKE_CXX_STANDARD 11)

add_executable(employee_ms main.cpp
        Employee.h
        Employee.cpp
        Worker.h
        Staff.cpp
        Staff.h
        Manager.cpp
        Manager.h
        Boss.cpp
        Boss.h
)
