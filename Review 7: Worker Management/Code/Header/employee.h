#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

typedef enum {
    Morning,
    Afternoon,
    Evening
} Time;

typedef struct {
    int Day;
    Time time;
} Shift;

class Employee {
private:
    string name;
    string title;
    int phone;
    Shift shift;

public:
    Employee() {
        this->name = "";
        this->title = "";
        this->phone= 0;
    }

    void setName(string _name);
    string getName();

    void setTitle(string _title);
    string setTitle();

    void setPhone(int _phone);
    int getPhone();

    void setShift(Shift _shift);
    Shift getShift();
};

class ManageEmployee {
private:
    list<Employee> employeeList;
public:
    ManageEmployee() {}

    void addEmployee(); // 1. Thêm nhân viên
    void editEmployee(); // 2. Sửa thông tin nhân viên
    void deleteEmployee(); // 3. Xóa nhân viên

    void setShift(); // 4. Set ca làm cho nhân viên
    void showEmployeeList(); // 5. Danh sách thông tin nhân viên
    void tableShift(); // 6. Thời gian làm việc

    void menuManageEmployee(); // menu quản lý nhân viên
};

#endif