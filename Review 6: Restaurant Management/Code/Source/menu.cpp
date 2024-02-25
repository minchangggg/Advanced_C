#include "../Header/menu.h"
using namespace std;

void mainMenu (Database &database) {
    while (1) {
    menu_start:
        Title title = managerWork;

        do {
            system("cls");

            cout << "\t\t\t-----------------------------" << endl;
            cout << "\t\t\t| RESTAURANT MANAGEMENT SYSTEM |" << endl;
            cout << "\t\t\t-----------------------------" << endl;
            cout << "\t\t\t 1. Manager" << endl;
            cout << "\t\t\t 2. Staff" << endl;
            cout << "\t\t\t 3. Exit program" << endl;
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

void menuManager (Database &database) {
menuManager_start:
    do {
        system("cls");

        cout << "\t\t\t-----------------------------" << endl;
        cout << "\t\t\t|       MANAGER WORKING      |" << endl;
        cout << "\t\t\t-----------------------------" << endl;
        cout << "\t\t\t 1. Set up table" << endl; // 1. Set up số bàn
        cout << "\t\t\t 2. Add dish" << endl; // 2. Thêm món
        cout << "\t\t\t 3. Edit dish" << endl; // 3. Sửa món
        cout << "\t\t\t 4. Delete dish" << endl; // 4. Xóa món
        cout << "\t\t\t 5. List of dishes" << endl; // 5. Danh sách món
        cout << "\t\t\t 6. Turn back main menu" << endl; // 6. 	Quay lại
        cout << "\t\t\t 7. Exit program" << endl;
        cout << "\t\t\t............................" << endl;
        cout << "\t\t\tPlease Enter Your Choice: ";
        cin >> choice;
    } while (choice < 1 || choice > 8);

    switch (choice) {
        case 1:
            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "----------------------------------------- Set up table ------------------------------------------------" << endl;
            cout << "\t\t\tEnter quantity of table you want to set up: ";
            cin >> database.numTable;
            database.managerData.setNumTable(database.numTable);
            database.staffaData.getNumTable(database.numTable);

            do {
                cout << "\n\t\t\t 1. Turn back manager menu" << endl;
                cout << "\t\t\t 2. Exit program" << endl;
                cout << "\t\t\tPlease Enter Your Choice: ";
                cin >> choice;   
                
                if (choice == 3) exit(0);

            } while (choice != 1);

            goto menuManager_start;
            break;

        case 2:
        add_menu:
            cout << "--------------------------------------------- Menu ----------------------------------------------------" << endl;
            database.managerData.showMenu();
            cout << endl << endl;

            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "----------------------------------------- Add dish ------------------------------------------------" << endl;
            database.managerData.addDish();

            do {
                cout << "\n\n\t\t\t 1. Continue Adding Another Dish " << endl;
                cout << "\n\t\t\t 2. Turn back manager menu" << endl;
                cout << "\t\t\t 3. Exit program" << endl;
                cout << "\t\t\tPlease Enter Your Choice: ";
                cin >> choice;

                if (choice == 3) exit(0);

            } while (choice != 1 && choice != 2);

            if (choice == 1) goto add_menu;
            else goto menuManager_start;
            break;

        case 3: {
        edit_menu:
            cout << "--------------------------------------------- Menu ----------------------------------------------------" << endl;
            database.managerData.showMenu();
            cout << endl << endl;

            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "------------------------------------------ Edit dish --------------------------------------------------" << endl;
            cout << "\nEnter ID of Dish you want to edit: ";
            int ID_input = 0; cin >> ID_input;

            do {
                cout << "1, Edit Name" << endl;
                cout << "2, Edit ID" << endl;
                cout << "3, Edit Price" << endl;
                cout << "Please Enter Your Choice: ";
                cin >> choice;
            } while (choice < 1 && choice >3);

            database.managerData.editDish(ID_input);

            do {
                cout << "\n\n\t\t\t 1. Continue Editing Another Dish " << endl;
                cout << "\n\t\t\t 2. Turn back manager menu" << endl;
                cout << "\t\t\t 3. Exit program" << endl;
                cout << "\t\t\tPlease Enter Your Choice: ";
                cin >> choice;

                if (choice == 3) exit(0);

            } while (choice != 1 && choice != 2);

            if (choice == 1) goto edit_menu;
            else goto menuManager_start;
            break;
        }

        case 4: {
        delete_menu:
            cout << "--------------------------------------------- Menu ----------------------------------------------------" << endl;
            database.managerData.showMenu();
            cout << endl << endl;

            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "----------------------------------------- Delete dish -------------------------------------------------" << endl;
            cout << "\nEnter ID of Dish you want to delete: ";
            int ID_input = 0; cin >> ID_input;

            database.managerData.deleteDish(ID_input);

            do {
                cout << "\n\n\t\t\t 1. Continue Deleting Another Dish " << endl;
                cout << "\n\t\t\t 2. Turn back manager menu" << endl;
                cout << "\t\t\t 3. Exit program" << endl;
                cout << "\t\t\tPlease Enter Your Choice: ";
                cin >> choice;

                if (choice == 3) exit(0);

            } while (choice != 1 && choice != 2);

            if (choice == 1) goto delete_menu;
            else goto menuManager_start;
            break;
        }

        case 5: {
            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "--------------------------------------------- Menu ----------------------------------------------------" << endl;
            database.managerData.showMenu();
            
            do {
                cout << "\n\t\t\t 1. Turn back manager menu" << endl;
                cout << "\t\t\t 2. Exit program" << endl;
                cout << "\t\t\tPlease Enter Your Choice: ";
                cin >> choice;   
                
                if (choice == 3) exit(0);

            } while (choice != 1);

            goto menuManager_start;
            break;
        }

        case 6:
            goto menuManager_start; 
            break;
        
        case 7: 
            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "------------------------------------- Program Is Exit --------------------------------------------" << endl;
            exit(0);
            break;

        default:
            break;  
    }
}

void menuStaff (Database &database) {
menuStaff_start:
    int _tableID = 0; 

    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t|       STAFF WORKING       |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    
    do {
        cout << "\t\t\tHave you booked a table?" << endl;
        cout << "\t\t\t1. Yes" << endl;
        cout << "\t\t\t2. No" << endl;
        cout << "\t\t\t............................" << endl;
        cout << "\t\t\tPlease Enter Your Choice: ";
        cin >> choice;
    } while (choice != 1 && choice !=2);

    if (choice == 1) {
        cout << "\t\t\tPlease Enter Your Table ID: ";
        cin >> _tableID;
        database.staffaData.chooseTable(_tableID);
    }

    else {
        database.staffaData.displayTable();

        if (database.staffaData.isFull()) {
            cout <<"Sorry. There are no tables available.";
            return;
        }

        else {
            cout << "\t\t\tPlease choose one of these Table ID: ";
            cin >> _tableID;
            database.staffaData.chooseTable(_tableID);
        }
    }

    orderMenu_start:
        do {
            cout << "\t\t\t 1. Add dish" << endl; 
            cout << "\t\t\t 2. Cancel dish " << endl; 
            cout << "\t\t\t 3. Edit dish" << endl; 
            cout << "\t\t\t 4. List of dish" << endl; 
            cout << "\t\t\t 5. Pay the bill" << endl;
            cout << "\t\t\t 6. Turn back staff menu" << endl;
            cout << "\t\t\t 7. Turn back main menu" << endl; 
            cout << "\t\t\t 8. Exit program" << endl;
            cout << "\t\t\t............................" << endl;
            cout << "\t\t\tPlease Enter Your Choice: ";
            cin >> choice;
        } while (choice < 1 || choice > 8);    

        switch (choice) {
            case 1: // 1. Gọi món
            add_order:
                cout << "--------------------------------------------- Menu ----------------------------------------------------" << endl;
                database.managerData.showMenu();
                cout << endl << endl;

                cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                cout << "----------------------------------------- Add dish ------------------------------------------------" << endl;
                database.staffaData.getTableInfo(_tableID, 1, database.managerData.getMenu());

                do {
                    cout << "\n\n\t\t\t 1. Continue Adding Another Order " << endl;
                    cout << "\n\t\t\t 2. Turn back Order menu" << endl;
                    cout << "\n\t\t\t 3. Turn back Staff menu" << endl;
                    cout << "\t\t\t 4. Exit program" << endl;
                    cout << "\t\t\tPlease Enter Your Choice: ";
                    cin >> choice;

                    if (choice == 4) exit(0);

                } while (choice != 1 && choice != 2 && choice != 3);

                if (choice == 1) goto add_order;
                else if (choice == 2) goto orderMenu_start;
                else goto menuStaff_start;
                break;

            case 2: { // 2. Hủy món
            delete_order:
                cout << "--------------------------------------------- Order ----------------------------------------------------" << endl;
                database.managerData.showMenu();
                cout << endl << endl;

                cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                cout << "---------------------------------------- Delete order -------------------------------------------------" << endl;
                cout << "\nEnter ID of order you want to delete: ";
                int ID_input = 0; cin >> ID_input;

                database.staffaData.getTableInfo(_tableID, 2, database.managerData.getMenu());

                do {
                    cout << "\n\n\t\t\t 1. Continue Deleting Another Order " << endl;
                    cout << "\n\t\t\t 2. Turn back Order menu" << endl;
                    cout << "\n\t\t\t 3. Turn back Staff menu" << endl;
                    cout << "\t\t\t 4. Exit program" << endl;
                    cout << "\t\t\tPlease Enter Your Choice: ";
                    cin >> choice;

                    if (choice == 4) exit(0);

                } while (choice != 1 && choice != 2 && choice != 3);

                if (choice == 1) goto delete_order;
                else if (choice == 2) goto orderMenu_start;
                else goto menuStaff_start;
                break;
            }

            case 3: { // 3. thay đổi (số lượng) món
            edit_order:
                cout << "--------------------------------------------- Order ----------------------------------------------------" << endl;
                database.managerData.showMenu();
                cout << endl << endl;

                cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                cout << "------------------------------------------ Edit order -------------------------------------------------" << endl;
                cout << "\nEnter ID of Dish you want to edit: ";
                int ID_input = 0; cin >> ID_input;

                database.staffaData.getTableInfo(_tableID, 3, database.managerData.getMenu());

                do {
                    cout << "\n\n\t\t\t 1. Continue Editing Another Order " << endl;
                    cout << "\n\t\t\t 2. Turn back Order menu" << endl;
                    cout << "\n\t\t\t 3. Turn back Staff menu" << endl;
                    cout << "\t\t\t 4. Exit program" << endl;
                    cout << "\t\t\tPlease Enter Your Choice: ";
                    cin >> choice;

                    if (choice == 4) exit(0);

                } while (choice != 1 && choice != 2 && choice != 3);

                if (choice == 1) goto edit_order;
                else if (choice == 2) goto orderMenu_start;
                else goto menuStaff_start;
                break;
            }

            case 4: // 4. Danh sách món đã đặt
                cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                cout << "--------------------------------------------- Order ---------------------------------------------------" << endl;
                database.staffaData.getTableInfo(_tableID, 4, database.managerData.getMenu());
                
                do {
                    cout << "\n\t\t\t 1. Turn back Order menu" << endl;
                    cout << "\n\t\t\t 2. Turn back Staff menu" << endl;
                    cout << "\t\t\t 3. Exit program" << endl;
                    cout << "\t\t\tPlease Enter Your Choice: ";
                    cin >> choice;

                    if (choice == 3) exit(0);

                } while (choice != 1 && choice != 2);

                if (choice == 1) goto orderMenu_start;
                else goto menuStaff_start;
                break;

            case 5: // 5. Thanh toán
                cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                cout << "\n-------------------------------------------Payment-----------------------------------------------------" << endl;
                database.staffaData.getTableInfo(_tableID, 5, database.managerData.getMenu());
                cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                break;

            case 6: // 6. Quay lại
                goto menuStaff_start;
                break;

            case 7: 
                break;

            case 8:
                cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                cout << "------------------------------------- Program Is Exit --------------------------------------------" << endl;
                exit(0);

            default:
                break;
        }
}
