#include "employee.h"
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

void Employee::setShift(Time _shift[5][2]) {
    shift[5][2] = _shift[5][2];
}

Time Employee::getShift() {
    return shift[5][2];
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
            cout << "Please enter new title: ";
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

void ManageEmployee::setTimePerDay(Time &_time1, Time &_time2) {
    int choice = 0;
    //___________________________________________________________________________________
    do {
    cout << "1 for MORNING, 2 for AFTERNOON, 3 for EVENING and 4 for no SHIFT in that day" << endl;
    cout << "Please enter your choice: "; cin >> choice; 
    } while (choice < 1 || choice > 4);
    
    switch (choice) {
        case 1: 
            _time1 = Morning;
            break;
        case 2: 
            _time1 = Afternoon;
            break;
        case 3:
            _time1 = Evening;
            break;
        case 4:
            break;
        default:
            break;
    }
    //___________________________________________________________________________________
    if (choice != 4) {
        do {
        cout << "\n\nDo you want to enter more shifts (you can choose up to 2 shifts in 1 day)" << endl;
        cout << "1. yes \t\t 2. no" << endl;
        cout << "Please enter your choice: "; cin >> choice; 
        } while (choice != 1 && choice != 2);

        if (choice == 1) {
            do {
                cout << "1 for MORNING, 2 for AFTERNOON, 3 for EVENING" << endl;
                cout << "Please enter your choice: "; cin >> choice; 
            } while (choice < 1 || choice > 3);

            switch (choice) {
                case 1: 
                    _time2 = Morning;
                    break;
                case 2: 
                    _time2 = Afternoon;
                    break;
                case 3:
                    _time2 = Evening;
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
            Time _time[5][2]; 
            cout << "____________________________________________________________________________" << endl;
            cout << "____________________________SHIPTS FOR WEEK for week________________________" << endl;
            
            cout << "\n______________________________Shift for Monday______________________________" << endl;
            setTimePerDay(_time[0][0], _time[0][1]);
            
            cout << "\n______________________________Shift for Tuesday_____________________________" << endl;
            setTimePerDay(_time[1][0], _time[1][1]);

            cout << "\n_____________________________Shift for Wednesday____________________________" << endl;
            setTimePerDay(_time[2][0], _time[2][1]);
            
            cout << "\n______________________________Shift for Thurday______________________________" << endl;
            setTimePerDay(_time[3][0], _time[3][1]);

            cout << "\n______________________________Shift for Friday______________________________" << endl;
            setTimePerDay(_time[4][0], _time[4][1]);

            it->setShift(_time);
        }
    }  
} 

void ManageEmployee::showEmployeeList() {

} 

void ManageEmployee::tableShift() {

} 

void ManageEmployee::menuManageEmployee() {

} 
