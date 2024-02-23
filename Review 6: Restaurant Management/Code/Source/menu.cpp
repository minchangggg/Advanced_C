#include "menu.h"
using namespace std;

void mainMenu (Database database) {
    while (1) {
        Title title = managerWork;

        do {
            system("cls");

            cout << "\t\t\t-----------------------------" << endl;
            cout << "\t\t\t| RESTAURANT MANAGEMENT SYSTEM |" << endl;
            cout << "\t\t\t-----------------------------" << endl;
            cout << "\t\t\t 1. Manager" << endl;
            cout << "\t\t\t 2. Staff" << endl;
            cout << "\t\t\t 3. Exit" << endl;
            cout << "\t\t\t............................" << endl;
            cout << "\t\t\tPlease Enter Your Choice: ";
            cin >> choice;

            if (choice == 3 ) exit(0);

        } while (choice != 1 && choice != 2);

        if (choice == 1) title = managerWork;
        else title = staffWork;

        switch (title) {
            case managerWork:
                menuManager (database);
                break;

            case staffWork:
                menuStaff (database);
                break;

            default:
                break;
        }
    }
}

