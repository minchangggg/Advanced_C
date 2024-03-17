#ifndef __MENU_H
#define __MENU_H

#include <storage.h>
#include <cart.h>

using namespace std;

/*
* Struct: Database
* Description: This struct is used for containing data of supermarket billing system application
    customer: data of customer
    administrator: data of administrator
*/
typedef struct {
    Customer customer;
    Administrator administrator;
} Database;

/*
* Function: mainMenu
* Description: This function is used for managing the supermarket billing system application
* Input:   database
* Output:  return: None
*/
void mainMenu (Database &database) {
    while (1) {
    menu_start:
        int choice = 0;
        do {
            system("cls");

            cout << "\t\t\t------------------------------------------" << endl;
            cout << "\t\t\t| Supermarket Billing System Application |" << endl;
            cout << "\t\t\t------------------------------------------" << endl;
            cout << "\t\t\t 1. Customer" << endl;
            cout << "\t\t\t 2. Administrator" << endl;
            cout << "\t\t\t 3. Exit program" << endl;
            cout << "\t\t\t............................" << endl;
            cout << "\t\t\tPlease Enter Your Choice: ";
            cin >> choice;

            if (choice == 3 ) exit(0);

        } while (choice != 1 && choice != 2);

        switch (choice) {
        case 1:
            database.customer.menuCustom();
            break;

        case 2:
            database.administrator.menuAdmin();
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
