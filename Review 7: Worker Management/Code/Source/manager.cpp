#include "../Header/manager.h"
using namespace std; 

int Manager::getAccount() {
    return account;
}

int Manager::getPassword() {
    return password;
}

void Manager::menuManager(Database &database) {
menuManager_start:
    int _password = 0; int _account = 0; int _choice = 0; 

    cout << "\t\t\t\t\t\tLOG IN" << endl;

    cout << "\t\t\tPlease Enter Account / Phone number: ";
    cin >> _account;
 
    cout << "\t\t\tPlease Enter Password: ";
    cin >> _password;

    if ((getAccount() != _account) || (getPassword() != _password)) {
        cout << "\t\t\t The Password Is Incorrect!" << endl << endl;

        cout << "\t\t\t 1. Re-enter The Password" << endl;
        cout << "\t\t\t 2. Turn Back Main Menu " << endl;
        cout << "\t\t\t 3. Exit Program" << endl;
        cout << "\t\t\tPlease Enter Your Choice: ";
        cin >> _choice;

        switch (_choice) {
        case 1:
            goto menuManager_start;
            break;

        case 2:
            break;

        case 3:
            cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "------------------------------------- Program Is Exit --------------------------------------------" << endl;
            exit(0);
            break;

        default:
            break;
        }
    }

    else if((getAccount() == _account) && (getPassword() == _password)) {
        Function function;
        do {
            do {
                system("cls");

                cout << "\t\t\t-----------------------------" << endl;
                cout << "\t\t\t|       MANAGER WORKING     |" << endl;
                cout << "\t\t\t-----------------------------" << endl;
                cout << "\t\t\t 1. Employee Management" << endl; // 1. Quản lý nhân viên
                cout << "\t\t\t 2. Room Management" << endl;  // 2. Quản lý phòng
                cout << "\t\t\t 3. Service Management" << endl; // 3. Dịch vụ
                cout << "\t\t\t 4. Turn Back Main Menu" << endl; // 4. Về lại menu chính
                cout << "\t\t\t 5. Exit Program" << endl; // 4. Dừng chương trình
                cout << "\t\t\t............................" << endl;
                cout << "\t\t\tPlease Enter Your Choice: ";
                cin >> _choice;

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
                    database.service.menuManageService();
                    break;

                case 4:
                    break;
                    
                case 5:
                    cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
                    cout << "------------------------------------- Program Is Exit --------------------------------------------" << endl;
                    exit(0);
                    break;

                default:
                    break;
            }
        } while (_choice !=4);
    }
}
