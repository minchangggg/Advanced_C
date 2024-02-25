#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

typedef enum { Morning, Afternoon, Evening, No_Shift } Time;

typedef struct {
    Time Mon[2];
    Time Tue[2];
    Time Wed[2];
    Time Thur[2];
    Time Fri[2];
} Shift;

string getTime (Time _time) {
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

class ManageEmployee {
private:
    list<Employee> employeeList;
public:
    ManageEmployee() {}

    void addEmployee(); // 1. Thêm nhân viên
    void editEmployee(int _ID); // 2. Sửa thông tin nhân viên
    void deleteEmployee(int _ID); // 3. Xóa nhân viên

    void setTimePerDay(Time day[2]);
    void setShift(int _ID); // 4. Set ca làm cho nhân viên

    void showEmployeeList(); // 5. Danh sách thông tin nhân viên
    void tableShift(); // 6. Thời gian làm việc

    void menuManageEmployee(); // menu quản lý nhân viên
};

#endif
