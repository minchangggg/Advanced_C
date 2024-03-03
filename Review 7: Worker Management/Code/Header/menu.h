#ifndef _MENU_H
#define _MENU_H

#include "../Header/receptionist.h"
#include "../Header/manager.h"

/*
* Function: menuHotel
* Description: This function is used for managing the hotel
* Input:   database
* Output:  return: None
*/
void menuHotel(Database &database) {
    Manager manager;
    Receptionist receptionist;

    while (1) {
    menu_start:
        int choice = 0;
        do {
            system("cls");

            cout << "\t\t\t-----------------------------" << endl;
            cout << "\t\t\t| RESTAURANT MANAGEMENT SYSTEM |" << endl;
            cout << "\t\t\t-----------------------------" << endl;
            cout << "\t\t\t 1. Manager" << endl;
            cout << "\t\t\t 2. Receptionist" << endl;
            cout << "\t\t\t 3. Exit program" << endl;
            cout << "\t\t\t............................" << endl;
            cout << "\t\t\tPlease Enter Your Choice: ";
            cin >> choice;

            if (choice == 3 ) exit(0);

        } while (choice != 1 && choice != 2);

        switch (choice) {
        case 1:
            manager.menuManager(database);
            break;

        case 2:
            receptionist.menuReceptionist(database);
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
}

#endif
