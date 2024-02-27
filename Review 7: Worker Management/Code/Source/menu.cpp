#include "../Header/menu.h"
using namespace std; 

void menuManager(Database &database) {
    while (1) {
    menu_start:
        Function function;

        do {
            system("cls");

            cout << "\t\t\t-----------------------------" << endl;
            cout << "\t\t\t| STAFF MANAGEMENT SYSTEM |" << endl;
            cout << "\t\t\t-----------------------------" << endl;
            cout << "\t\t\t 1. Employee Management" << endl; // 1. Quản lý nhân viên
            cout << "\t\t\t 2. Room Management" << endl;  // 2. Quản lý phòng
            cout << "\t\t\t 3. Service Management" << endl; // 3. Dịch vụ
            cout << "\t\t\t 4. Exit Program" << endl; // 4. Dừng chương trình
            cout << "\t\t\t............................" << endl;
            cout << "\t\t\tPlease Enter Your Choice: ";
            cin >> _choice;

            if (_choice == 4 ) exit(0);

        } while (_choice != 1 && _choice != 2 && _choice != 3 );

        if (_choice == 1) function = Employee_function;
        else if (_choice ==2) function = Room_function;
        else function = Service_function;

        switch (function) {
            case Employee_function:
                database.employee.menuManageEmployee();
                break;
            
            case Room_function:
                database.room.menuManageRoom();
                break;

            case Service_function:
                // database.service.menuManageService();
                break;

            default:
                break;
        }
    }
}
