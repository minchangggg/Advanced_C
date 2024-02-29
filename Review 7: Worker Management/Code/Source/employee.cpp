#include "../Header/employee.h"
using namespace std;

// class Employee _______________________________________________________________________________________________

void Employee::setID (int _ID) {
    ID = _ID;
}

int Employee::getID() {
    return ID;
}

void Employee::setName(string _name) {
    name = _name;
}

string Employee::getName() {
    return name;
}

void Employee::setTitle(string _title) {
    title = _title;
}

string Employee::getTitle() {
    return title;
}

void Employee::setPhone(int _phone) {
    phone = _phone;
}

int Employee::getPhone() {
    return phone;
}

void Employee::setData() {
    cout << "\t\t\tEnter Name: ";
    string _name; 
    cin.ignore();
    cin >> _name;
    setName(_name);

    cout << "\t\t\tEnter Phone Number: ";
    int _phone; cin >> _phone;
    setPhone(_phone);

    cout << "\t\t\tEnter Title: ";
    string _title; 
    cin.ignore();
    cin >> _title;
    setTitle(_title);
}

void Employee::setShift(Shift _shift) {
    shift = _shift;
}

Shift Employee::getShift() {
    return shift;
}

// class ManageEmployee _______________________________________________________________________________________________

void ManageEmployee::addEmployee() {
    Employee newEmployee;
    newEmployee.setData();

    employeeList.push_back(newEmployee);
} 

void ManageEmployee::editEmployee(int _ID) {
    list<Employee>::iterator it;
    for (it = employeeList.begin(); it != employeeList.end(); ++it) {
        if (it->getID() == _ID) {
            cout << "\t\t\tPlease enter new title: ";
            string _newtitle; 
            cin.ignore();
            cin >> _newtitle;
            it->setTitle(_newtitle);            
        }
    }
} 

void ManageEmployee::deleteEmployee(int _ID) {
    list<Employee>::iterator it;
    for (it = employeeList.begin(); it != employeeList.end(); ++it) {
        if (it->getID() == _ID) {
            employeeList.erase(it);
        }
    }
} 

void ManageEmployee::setTimePerDay(Time day[2]) {
    int choiceTime = 0;

    do {
        cout << "1 for MORNING, 2 for AFTERNOON, 3 for EVENING and 4 for no SHIFT in that day" << endl;
        cout << "Please enter your choice: "; cin >> choiceTime; 
    } while (choiceTime < 1 || choiceTime > 4);
    
    switch (choiceTime) {
        case 1: 
            day[0] = Morning;
            break;
        case 2: 
            day[0] = Afternoon;
            break;
        case 3:
            day[0] = Evening;
            break;
        case 4:
            break;
        default:
            break;
    }

    if (choiceTime != 4) {
        do {
            cout << "\n\nDo you want to enter more shifts (you can choose up to 2 shifts in 1 day)" << endl;
            cout << "1. yes \t\t 2. no" << endl;
            cout << "Please enter your choice: "; cin >> choiceTime; 
        } while (choiceTime != 1 && choiceTime != 2);

        if (choiceTime == 1) {
            do {
                cout << "1 for MORNING, 2 for AFTERNOON, 3 for EVENING" << endl;
                cout << "Please enter your choice: "; cin >> choiceTime; 
            } while (choiceTime < 1 || choiceTime > 3);

            switch (choiceTime) {
                case 1: 
                    day[1] = Morning;
                    break;
                case 2: 
                    day[1] = Afternoon;
                    break;
                case 3:
                    day[1] = Evening;
                    break;
                default:
                    break;
            }
        }
    }
}

void ManageEmployee::setShift(int _ID) {
    list<Employee>::iterator it;
    for (it = employeeList.begin(); it != employeeList.end(); ++it) {
        if (it->getID() == _ID) {
            Shift day; 

            cout << "\n             ______________________________Shift for Monday______________________________              " << endl;
            setTimePerDay(day.Mon);
            
            cout << "\n             ______________________________Shift for Tuesday_____________________________              " << endl;
            setTimePerDay(day.Tue);

            cout << "\n             _____________________________Shift for Wednesday____________________________              " << endl;
            setTimePerDay(day.Wed);
            
            cout << "\n             ______________________________Shift for Thurday______________________________              " << endl;
            setTimePerDay(day.Thur);

            cout << "\n             ______________________________Shift for Friday______________________________              " << endl;
            setTimePerDay(day.Fri);

            it->setShift(day);
        }
    }  
} 

void ManageEmployee::showEmployeeList() {
    int count = 0;
    cout << "\tNo" << "\t\tID" << "\t\tName" << "\t\tPhone Number" << "\t\tTitle" << endl;
    cout << "______________________________________________________________________________________________________________________________________________" << endl;
    
    for (auto i : employeeList) {
        count++;
        cout << "\t" << count << "\t\t" << i.getID() << "\t\t" << i.getName() << "\t\t" << i.getPhone() << "\t\t" << i.getID() << endl;
    }
} 

void ManageEmployee::tableShift() {
    cout << "\tName" << "\t\tMon" << "\t\tTue" << "\t\tWed" << "\t\tThur" << "\t\tFri" << endl;
    cout << "______________________________________________________________________________________________________________________________________________" << endl;
    
    for (auto i : employeeList) {
        cout << "\t" << i.getName() << "\t\t" << getTime(i.getShift().Mon[0]) << "\t\t" << getTime(i.getShift().Tue[0]) << "\t\t" << getTime(i.getShift().Wed[0]) << "\t\t" << getTime(i.getShift().Thur[0]) << "\t\t" << getTime(i.getShift().Fri[0]) << endl;
        cout << "\t\t\t\t" << getTime(i.getShift().Mon[1]) << "\t\t" << getTime(i.getShift().Tue[1]) << "\t\t" << getTime(i.getShift().Wed[1]) << "\t\t" << getTime(i.getShift().Thur[1]) << "\t\t" << getTime(i.getShift().Fri[1]) << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    }
} 

void ManageEmployee::menuManageEmployee() {
menuManageEmployee_start:
    int _choice = 0;
    cout << "\t\t\t-------------------------------" << endl;
    cout << "\t\t\t|     EMPLOYEE MANAGEMENT     |" << endl;
    cout << "\t\t\t-------------------------------" << endl;
    do { 
        cout << "\t\t\t 1. Add New Employee Details" << endl; // 1. Thêm nhân viên
        cout << "\t\t\t 2. Modify Employee Detail" << endl; // 2. Sửa thông tin nhân viên
        cout << "\t\t\t 3. Delete Employee Detail" << endl; // 3. Xóa nhân viên
        cout << "\t\t\t 4. Set Weekly Shift For Employee" << endl; // 4. Set ca làm cho nhân viên
        cout << "\t\t\t 5. Employee List" << endl; // 5. Danh sách thông tin nhân viên
        cout << "\t\t\t 6. Weekly Shift Timetable " << endl; // 6. Thời gian làm việc
        cout << "\t\t\t 7. Turn Back Manager Menu " << endl; // 7. Quay lại main menu
        cout << "\t\t\t 8. Exit" << endl; // 8. Thoát
        cout << "\t\t\t............................" << endl;
        cout << "\t\t\tPlease Enter Your Choice: ";
        cin >> _choice;
    } while (_choice < 1 || _choice > 8);

    switch (_choice) {
        case 1: // 1. Thêm nhân viên
        add_employee:
            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "------------------------------------ Add New Employee Details -----------------------------------------" << endl;
            addEmployee();
            cout << "\n----------------------------- Successfully Add New Employee Details -----------------------------------" << endl;

            do {
                cout << "\n\n\t\t\t 1. Continue Adding Another Employee Details" << endl;
                cout << "\t\t\t 2. Turn Back Employee Menu " << endl;
                cout << "\t\t\tPlease Enter Your Choice: ";
                cin >> _choice;
            } while (_choice != 1 && _choice != 2);

            if (_choice == 1) goto add_employee;
            else goto menuManageEmployee_start;

            break;

        case 2: // 2. Sửa thông tin nhân viên
        modify_employee:
            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "------------------------------------- Modify Employee Detail ------------------------------------------" << endl;
            cout << "\t\t\tEnter ID of Student which you want to modify: ";
            int _ID_input = 0; cin >> _ID_input;
            editEmployee(_ID_input);
            cout << "\n---------------------------- Successfully Modify Employee Detail --------------------------------------" << endl;

            do {
                cout << "\n\n\t\t\t 1. Continue Modifying Another Employee Details" << endl;
                cout << "\t\t\t 2. Turn Back Employee Menu " << endl;
                cout << "\t\t\tPlease Enter Your Choice: ";
                cin >> _choice;
            } while (_choice != 1 && _choice != 2);

            if (_choice == 1) goto modify_employee;
            else goto menuManageEmployee_start;

            break;

        case 3: // 3. Xóa nhân viên
        delete_employee:
            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "------------------------------------- Delete Employee Detail ------------------------------------------" << endl;            
            cout << "\nEnter ID of Student which you want to delete: ";
            int _ID_input = 0; cin >> _ID_input;
            deleteEmployee(_ID_input);
            cout << "\n---------------------------- Successfully Delete Employee Detail --------------------------------------" << endl;

            do {
                cout << "\n\n\t\t\t 1. Continue Deleting Another Employee Details" << endl;
                cout << "\t\t\t 2. Turn Back Employee Menu " << endl;
                cout << "\t\t\tPlease Enter Your Choice: ";
                cin >> _choice;
            } while (_choice != 1 && _choice != 2);

            if (_choice == 1) goto delete_employee;
            else goto menuManageEmployee_start;

            break;
        
        case 4: // 4. Set ca làm cho nhân viên
        set_weekly_shift:
            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "--------------------------------- Set Weekly Shift For Employee----------------------------------------" << endl;            
            cout << "\nEnter ID of Student which you want to set weekly shift: ";
            int _ID_input = 0; cin >> _ID_input;
            setShift(_ID_input);
            cout << "\n-------------------------- Successfully Set Weekly Shift For Employee ---------------------------------" << endl;

            do {
                cout << "\n\n\t\t\t 1. Continue Set Weekly Shift For Another Employee" << endl;
                cout << "\t\t\t 2. Turn Back Employee Menu " << endl;
                cout << "\t\t\tPlease Enter Your Choice: ";
                cin >> _choice;
            } while (_choice != 1 && _choice != 2);

            if (_choice == 1) goto set_weekly_shift;
            else goto menuManageEmployee_start;

            break;

        case 5: // 5. Danh sách thông tin nhân viên
            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "--------------------------------------- Employee List -------------------------------------------------" << endl;
            showEmployeeList();
            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;

            do { 
                cout << "\n\n\t\t\t Enter 1 To Turn Back Employee Menu " << endl;
                cout << "\t\t\tPlease Enter Your Choice: ";
                cin >> _choice;
            } while (_choice != 1);

            goto menuManageEmployee_start;

            break;
        
        case 6: // 6. Thời gian làm việc
            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "------------------------------------Weekly Shift Timetable --------------------------------------------" << endl;    
            tableShift();
            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;

            do { 
                cout << "\n\n\t\t\t Enter 1 To Turn Back Employee Menu " << endl;
                cout << "\t\t\tPlease Enter Your Choice: ";
                cin >> _choice;
            } while (_choice != 1);

            goto menuManageEmployee_start;           

        case 7: // 7. Quay lại Manager menu
            break;

        case 8: // 8. Thoát
            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "--------------------------------------- Program Is Exit -----------------------------------------------" << endl;
            exit(0);

        default:
            break;
    }
} 
