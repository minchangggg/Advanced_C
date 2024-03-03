/*
* File: employee.h
* Author: Ton Nu Minh Trang
* Date: 15/02/2024
* Description: This file is a Employee header file which manages employees of hotel
*/

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

typedef enum { Morning, Afternoon, Evening, No_Shift } Time;

/*
* Struct: Shift
* Description: This struct is used for setting weekly shift 
    Mon[2]: shift for Monday  
    Tue[2]: shift for Tuesday 
    Wed[2]: shift for Wednesday 
    Thur[2]: shift for Thurday 
    Fri[2]: shift for Friday 
*/
typedef struct {
    Time Mon[2];
    Time Tue[2];
    Time Wed[2];
    Time Thur[2];
    Time Fri[2];
} Shift;

inline string getTime (Time _time) {
    string time;
    switch (_time) {
        case Morning:
            time = " Morning ";
            break;
        case Afternoon:
            time = "Afternoon";
            break;
        case Evening: 
            time = " Evening ";
            break;
        case No_Shift:
            time = "    x    ";
            break;
        default:
            break;
    }
    return time;
}

/*
*Class: Employee
*Description: This class contains basic properties and methods of a Employee object
*/
class Employee {
private:
    int ID;
    string name;
    string title;
    int phone;
    Shift shift; 

public:
    Employee() {
        static int _ID = 1;
        this->ID = _ID;
        _ID++;

        this->name = "";
        this->title = "";
        this->phone= 0;
    }

    void setID (int _ID);
    int getID();

    void setName(string _name);
    string getName();

    void setTitle(string _title);
    string getTitle();

    void setPhone(int _phone);
    int getPhone();

    void setData();

    void setShift(Shift _shift);
    Shift getShift();
};

/*
*Class: ManageEmployee
*Description: This class contains basic properties and methods that manage employees of hotel
*/
class ManageEmployee {
private:
    list<Employee> employeeList;
public:
    ManageEmployee() {}

    void addEmployee(); 
    void editEmployee(int _ID); 
    void deleteEmployee(int _ID); 

    void setTimePerDay(Time day[2]);
    void setShift(int _ID); 

    void showEmployeeList(); 
    void tableShift(); 

    void menuManageEmployee(); 
};

#endif
