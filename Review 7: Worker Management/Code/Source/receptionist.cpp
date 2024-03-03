/*
* File: receptionist.cpp
* Author: Ton Nu Minh Trang
* Date: 15/02/2024
* Description: This file contains all the functions/methods to helps hotel system work
*/

#include "../Header/receptionist.h"
using namespace std; 

/*
* Class: Receptionist
* Function: setAccountt
* Description: This function is used for setting receptionist account
* Input:   _accountt (account of manager)
* Output:  return: None
*/
void Receptionist::setAccountt(int _accountt) {
    accountt = _accountt;
}

/*
* Class: Receptionist
* Function: setPasswordd
* Description: This function is used for setting receptionist password 
* Input:   _passwordd (password of employee)
* Output:  return: None
*/
void Receptionist::setPasswordd(int _passwordd) {
    passwordd = _passwordd;
}

/*
* Class: Receptionist
* Function: getAccountt
* Description: This function is used for getting receptionist account
* Input:   None
* Output:  return: accountt (account of manager)
*/
int Receptionist::getAccountt() {
    return accountt;
}

/*
* Class: Receptionist
* Function: getPasswordd
* Description: This function is used for getting receptionist password 
* Input:   None
* Output:  return: passwordd (password of employee)
*/
int Receptionist::getPasswordd() {
    return passwordd;
}

/*
* Class: Receptionist
* Function: checkShift
* Description: This function is used for displaying weekly shift timetable of employees
* Input:   database 
* Output:  return: None
*/
void Receptionist::checkShift(Database database) {
    database.employee.tableShift();
}

/*
* Class: Receptionist
* Function: makeCheckIn
* Description: This function is used for check-in the hotel
* Input:   database
* Output:  return: None
*/
void Receptionist::makeCheckIn(Database &database) {
    database.room.showRoom();
    cout << "\t\t\tPlease choose one of these Room ID: ";
    string _ID = ""; 
    cin.ignore(); cin >> _ID;

    list<Room>::iterator it;
    for (it =  database.room.getRoomList().begin(); it !=  database.room.getRoomList().end(); ++it) {
        if (it->getRoomID() == _ID) {
            it->getRoom();
        }
    }
}

/*
* Class: Receptionist
* Function: makeCheckOut
* Description: This function is used for check-out the hotel
* Input:   database
* Output:  return: None
*/
void Receptionist::makeCheckOut(Database &database) {
    int _phoneCustomer;
    cout << "Please enter customer phone number:";
    cin >> _phoneCustomer;

    for (auto i : database.room.getRoomList()) {
        for (auto j : i.getCustomerList()) {
            if (j.getPhoneCustomer() == _phoneCustomer) {
                cout << "Customer Details:" << endl;
                cout << "Name: " << j.getNameCustomer() << endl;
                cout << "Phone Number: " << j.getPhoneCustomer() << endl;
                cout << "Room ID: " << i.getRoomID() << endl;
                cout << "Time checkin: " << j.getCheckIn().Time << " - " << j.getCheckIn().Date << endl;
                cout << "Time checkout: " << j.getCheckOut().Time << " - " << j.getCheckOut().Date << endl;

                cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
                i.getBill();
                cout << "Feedback: " << j.getFeedback() << endl;
                cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
                
                int ans = 0;
                do {
                    cout << "\n\n\t\t\t1. Pay away" << endl;
                    cout << "\t\t\t2. Turn back" << endl;
                    cout << "\t\t\tPlease Enter Your Choice: " << endl;
                    cin >> ans;
                } while (ans != 1);
                i.resetTable();
                
                return;
            }
        }
    }

    makeCheckOut(database);
}

/*
* Class: Receptionist
* Function: showRoom
* Description: This function is used for displaying rooms of hotel
* Input:   database
* Output:  return: None
*/
void Receptionist::showRoom(Database database) {
    database.room.showRoom();
}

/*
* Class: Receptionist
* Function: menuReceptionist
* Description: This function is used for serving rooms and services of hotel for customer
* Input:   database
* Output:  return: None
*/
void Receptionist::menuReceptionist(Database &database) { 
    int _passwordd = 0; int _accountt = 0; int _choicee = 0; 

    cout << "\t\t\t\t\t\tLOG IN" << endl;

    cout << "\t\t\tPlease Enter Account / Phone number: ";
    cin >> _accountt;
 
    cout << "\t\t\tPlease Enter Password: ";
    cin >> _passwordd;

    if ((getAccountt() != _accountt) || (getPasswordd() != _passwordd)) {
        cout << "\t\t\t The Password Is Incorrect!" << endl;
        cout << "\t\t\t --------------------------" << endl;
        cout << "\t\t\t 1. Re-enter The Password" << endl;
        cout << "\t\t\t 2. Turn Back Main Menu " << endl;
        cout << "\t\t\t 3. Exit Program" << endl;
        cout << "\t\t\tPlease Enter Your Choice: ";
        cin >> _choicee;

        switch (_choicee) {
        case 1:
            goto menuReceptionist_start;
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

    else if((getAccountt() == _accountt) && (getPasswordd() == _passwordd)) {
    menuReceptionist_start: 
        do {
            system("cls");

            cout << "\t\t\t-----------------------------" << endl;
            cout << "\t\t\t|    RECEPTIONIST WORKING   |" << endl;
            cout << "\t\t\t-----------------------------" << endl;
            cout << "\t\t\t 1. Weekly Shift Timetable" << endl; // 1. Xem ca làm
            cout << "\t\t\t 2. Edit Receptionist Account" << endl;  // 2. Sửa thông tin
            cout << "\t\t\t 3. Check In For Customer" << endl; // 3. Đặt phòng cho khách
            cout << "\t\t\t 4. Set Service For Customer" << endl; // 4. Set dịch vụ
            cout << "\t\t\t 5. Check Out for Customer" << endl; // 5. Trả phòng cho khách
            cout << "\t\t\t 6. List Of Rooms" << endl; // 6. Danh sách phòng
            cout << "\t\t\t 7. Turn Back Main Menu" << endl; // 7. Về lại menu chính
            cout << "\t\t\t 8. Exit Program" << endl; // 8. Thoát ctr
            cout << "\t\t\t............................" << endl;
            cout << "\t\t\tPlease Enter Your Choice: ";
            cin >> _choicee;

        } while (_choicee < 1 || _choicee > 8);

        string _roomID = 0;
        switch (_choicee) {
            case 1:
                cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
                cout << "------------------------------------Weekly Shift Timetable --------------------------------------------" << endl;    
                checkShift(database);
                cout << "\n-------------------------------------------------------------------------------------------------------" << endl;

                do { 
                    cout << "\n\n\t\t\t Enter 1 To Turn Back Receptionist Menu " << endl;
                    cout << "\t\t\tPlease Enter Your Choice: ";
                    cin >> _choicee;
                } while (_choicee != 1);

                goto menuReceptionist_start;  
                break;

            case 2:
                cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
                cout << "Please Enter New Account/ Phone Number You Want To Change: " << endl;
                cin >> _accountt; setAccountt(_accountt);

                cout << "Please Enter New Password You Want To Change" << endl;
                cin >> _passwordd; setPasswordd(_passwordd);
                cout << "\n----------------------------- Successfully Setting New Password ---------------------------------------" << endl;
                
                do { 
                    cout << "\n\n\t\t\t Enter 1 To Turn Back Receptionist Menu " << endl;
                    cout << "\t\t\tPlease Enter Your Choice: ";
                    cin >> _choicee;
                } while (_choicee != 1);

                goto menuReceptionist_start;  
                break;

            case 3:
                cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
                
                if (database.room.isFull()) cout <<"Sorry. There are no tables available.";
                
                else makeCheckIn(database);
            
                do { 
                    cout << "\n\n\t\t\t Enter 1 To Turn Back Receptionist Menu " << endl;
                    cout << "\t\t\tPlease Enter Your Choice: ";
                    cin >> _choicee;
                } while (_choicee != 1);

                goto menuReceptionist_start;  
                break;
            
            case 4: {
                cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
                cout << "Enter ID Of Room  You Want To Add Type Of Services: " << endl;
                cin.ignore(); cin >> _roomID;

                add_service_order:
                    list<Room>::iterator it;
                    for (it =  database.room.getRoomList().begin(); it !=  database.room.getRoomList().end(); ++it) {
                        if (it->getRoomID() == _roomID) {
                            it->addOrder(database.service);
                            cout << "\n---------------------------------- Successfully Add Detail --------------------------------------------" << endl;
                        }
                    }

                    do {
                        cout << "\n\n\t\t\t 1. Continue Adding Another Type Of Service " << endl;
                        cout << "\t\t\t 2. Turn Back Receptionist Menu " << endl;
                        cout << "\t\t\tPlease Enter Your Choice: ";
                        cin >> _choicee;
                    } while (_choicee != 1 && _choicee != 2);

                    if (_choicee == 1) goto add_service_order;
                    else goto menuReceptionist_start;
                    break;
            }

            case 5:
                cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
                makeCheckOut(database);
                cout << "\n--------------------------------- Successfully Check Out ----------------------------------------------" << endl;

                do { 
                    cout << "\n\n\t\t\t Enter 1 To Turn Back Receptionist Menu " << endl;
                    cout << "\t\t\tPlease Enter Your Choice: ";
                    cin >> _choicee;
                } while (_choicee != 1);

                goto menuReceptionist_start;  
                break;

            case 6:
                cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
                showRoom(database);

                do { 
                    cout << "\n\n\t\t\t Enter 1 To Turn Back Receptionist Menu " << endl;
                    cout << "\t\t\tPlease Enter Your Choice: ";
                    cin >> _choicee;
                } while (_choicee != 1);

                goto menuReceptionist_start;  
                break;

            case 7:
                break;

            case 8:
                cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
                cout << "------------------------------------- Program Is Exit --------------------------------------------" << endl;
                exit(0);
                break;

            default:
                break;
        }

    } while (_choicee != 7);
}
