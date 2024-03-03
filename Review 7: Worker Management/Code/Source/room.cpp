/*
* File: room.cpp
* Author: Ton Nu Minh Trang
* Date: 15/02/2024
* Description: This file contains all the functions/methods to manage rooms of hotel
*/

#include "../Header/room.h"
using namespace std;

/*
* Class: Customer
* Function: setNameCustomer
* Description: This function is used for setting name of customer
* Input:   _name (name of customer)
* Output:  return: None
*/
void Customer::setNameCustomer(string _name) {
    nameCustomer = _name;
}

/*
* Class: Customer
* Function: getNameCustomer
* Description: This function is used for getting name of customer
* Input:   None
* Output:  return: name (name of customer)
*/
string Customer::getNameCustomer() {
    return nameCustomer;
}

/*
* Class: Customer
* Function: setPhoneCustomer
* Description: This function is used for setting phone number of customer
* Input:   _phone (phone number of customer)
* Output:  return: None
*/
void Customer::setPhoneCustomer(int _phone) {
    phoneCustomer = _phone;
}

/*
* Class: Customer
* Function: getPhoneCustomer
* Description: This function is used for getting phone number of customer
* Input:   None 
* Output:  return: phone (phone number of customer)
*/
int Customer::getPhoneCustomer() {
    return phoneCustomer;
}

/*
* Class: Customer
* Function: setCheckIn
* Description: This function is used for setting check-in time of customer
* Input:   _checkIn (check-in time of customer) 
* Output:  None
*/
void Customer::setCheckIn (CheckTime _checkIn) {
    checkIn = _checkIn;
}

/*
* Class: Customer
* Function: setCheckOut
* Description: This function is used for setting check-out time of customer
* Input:   _checkOut (check-out time of customer) 
* Output:  None
*/
void Customer::setCheckOut (CheckTime _checkOut) {
    checkOut = _checkOut;
}

/*
* Class: Customer
* Function: getCheckIn
* Description: This function is used for getting check-in time of customer
* Input:   None 
* Output:  return: checkIn (check-in time of customer) 
*/
CheckTime Customer::getCheckIn() {
    return checkIn;
}

/*
* Class: Customer
* Function: getCheckOut
* Description: This function is used for getting check-out time of customer
* Input:   None 
* Output:  return: checkOut (check-out time of customer) 
*/
CheckTime Customer::getCheckOut() {
    return checkOut;
}

/*
* Class: Customer
* Function: setFeedback
* Description: This function is used for setting feedback of customer
* Input:   _feedback (feedback of customer)
* Output:  return: None
*/
void Customer::setFeedback(string _feedback) {
    feedback = _feedback;
}

/*
* Class: Customer
* Function: getFeedback
* Description: This function is used for getting feedback of customer
* Input:   None
* Output:  return: feedback (feedback of customer)
*/
string Customer::getFeedback() {
    return feedback;
}

/*
* Class: Room
* Function: getOrderService
* Description: This function is used for getting orderService (list of ordered services) of customer
* Input:   None
* Output:  return: orderService (list of ordered services)
*/
list<Order> Room::getOrderService() {
    return orderService;
}  

/*
* Class: Room
* Function: getCustomerList
* Description: This function is used for getting customerList (list of customers) of customer
* Input:   None
* Output:  return: customerList (list of customers)
*/
list<Customer> Room::getCustomerList() {
    return customerList;
}

/*
* Class: Room
* Function: setRoomID
* Description: This function is used for setting room ID 
* Input:   _roomID (room ID)
* Output:  return: None
*/
void Room::setRoomID(string _roomID) {
    roomID = _roomID;
}

/*
* Class: Room
* Function: getRoomID
* Description: This function is used for getting room ID 
* Input:   None
* Output:  return: roomID (room ID)
*/
string Room::getRoomID() const {
    return roomID;
}

/*
* Class: Room
* Function: setStatus
* Description: This function is used for setting status of room  
* Input:   _status (status of room)
* Output:  return: None
*/
void Room::setStatus(Status _status) {
    status = _status;
}

/*
* Class: Room
* Function: getStatus
* Description: This function is used for getting status of room 
* Input:   None
* Output:  return: status (status of room)
*/
Status Room::getStatus() {
    return status;
}

/*
* Class: Room
* Function: getRoom
* Description: This function is used for setting information of room 
* Input:   None
* Output:  None
*/
void Room::getRoom() {
    setStatus(U);

    Customer newCustomer;

    string _name; int _num;
    cout << "Please enter customer name: ";
    cin.ignore(); cin >> _name;
    cout << "Please enter customer phone number: ";
    cin.ignore(); cin >> _num;

    CheckTime _checkTime;
    cout << "Please enter time customer Check in: ";
    cin.ignore(); cin >> _checkTime.Date;
    cout << "Please enter date customer Check in: ";
    cin.ignore(); cin >> _checkTime.Time;

    newCustomer.setNameCustomer(_name);
    newCustomer.setPhoneCustomer(_num);
    newCustomer.setCheckIn(_checkTime);

    customerList.push_back(newCustomer);
}

/*
* Class: Room
* Function: resetTable
* Description: This function is used for reseting status of room 
* Input:   None
* Output:  None
*/
void Room::resetTable() {
    setStatus(A);
}

/*
* Class: Room
* Function: addOrder
* Description: This function is used for adding services
* Input:   manageService (type of services)
* Output:  None
*/
void Room::addOrder(ManageService manageService) {
    int ans = 0;
    do{
        cout << "\t\t\tSelect the type of service you want to use from the categories below" << endl;
        cout << "\t\t\t1. Food and Beverage" << endl;
        cout << "\t\t\t2. Pool" << endl;
        cout << "\t\t\t3. Gym" << endl;
        cout << "\t\t\t4. Laundry" << endl;
        cout << "\t\t\tPlease Enter Your Choice: " << endl;
    } while (ans < 1 || ans > 4);

    Order newOrder; int _ID; int _num; 

    switch(ans) {
        case 1: {
            cout << "\n\n--------------------------------------------- Menu ----------------------------------------------------" << endl;
            manageService.showService(manageService.getDish());

            cout << "\n\n\t\t\tEnter ID of Dish you want: ";
            cin >> _ID;

            list<Service>::iterator it;
            for (it = manageService.getDish().begin(); it != manageService.getDish().end(); ++it) {
                if (it->getID() == _ID) {
                    newOrder.typeService.setID(it->getID());
                    newOrder.typeService.setName(it->getName());
                    newOrder.typeService.setPrice(it->getPrice());
                    break;
                }
            }

            cout << "Enter quantity of dish you want: ";
            cin >> _num;
            newOrder.numService = _num;  

            orderService.push_back(newOrder);

            break;
        }

        case 2: {
            cout << "\n\n--------------------------------------------- Menu ----------------------------------------------------" << endl;
            manageService.showService(manageService.getPool());

            cout << "\n\n\t\t\tEnter ID's type of Pool services you want: ";
            cin >> _ID;

            list<Service>::iterator it;
            for (it = manageService.getPool().begin(); it != manageService.getPool().end(); ++it) {
                if (it->getID() == _ID) {
                    newOrder.typeService.setID(it->getID());
                    newOrder.typeService.setName(it->getName());
                    newOrder.typeService.setPrice(it->getPrice());
                    break;
                }
            }

            cout << "Enter quantity for type of Pool services you want: ";
            cin >> _num;
            newOrder.numService = _num;  

            orderService.push_back(newOrder);

            break;
        }

        case 3: {
            cout << "\n\n--------------------------------------------- Menu ----------------------------------------------------" << endl;
            manageService.showService(manageService.getGym());

            cout << "\n\n\t\t\tEnter ID's type of Gym services you want: ";
            cin >> _ID; 

            list<Service>::iterator it;
            for (it = manageService.getGym().begin(); it != manageService.getGym().end(); ++it) {
                if (it->getID() == _ID) {
                    newOrder.typeService.setID(it->getID());
                    newOrder.typeService.setName(it->getName());
                    newOrder.typeService.setPrice(it->getPrice());
                    break;
                }
            }

            cout << "Enter quantity for type of Gym services you want: ";
            cin >> _num;
            newOrder.numService = _num;  

            orderService.push_back(newOrder);

            break;
        }

        case 4: {
            cout << "\n\n--------------------------------------------- Menu ----------------------------------------------------" << endl;
            manageService.showService(manageService.getLaundry());

            cout << "\n\n\t\t\tEnter ID's type of Laundry services you want: ";
            cin >> _ID;

            list<Service>::iterator it;
            for (it = manageService.getLaundry().begin(); it != manageService.getLaundry().end(); ++it) {
                if (it->getID() == _ID) {
                    newOrder.typeService.setID(it->getID());
                    newOrder.typeService.setName(it->getName());
                    newOrder.typeService.setPrice(it->getPrice());
                    break;
                }
            }

            cout << "Enter quantity for type of Laundry services you want: ";
            cin >> _num;
            newOrder.numService = _num;  

            orderService.push_back(newOrder);

            break;
        }

        default:
            break;
    }
}

/*
* Class: Room
* Function: addOrder
* Description: This function is used for displaying list of ordered services
* Input:   None
* Output:  None
*/
void Room::getOrderList() {
    int count = 0;
    cout << "\t\t\t\t\tList Of Your Used Service" << endl << endl;
    cout << "No" << "\t\tName" << "\t\tPrice" << "\t\tQuantity" << endl;
    for (auto i : orderService) {
        count++;
        cout << count << "\t\t" << i.typeService.getName() << "\t\t" << i.typeService.getPrice() << "\t\t" << i.numService << endl;
    }
}

/*
* Class: Room
* Function: addOrder
* Description: This function is used for displaying bill
* Input:   None
* Output:  None
*/
void Room::getBill() {
    int _totalBill = 0;
    for (auto i : orderService) {
        _totalBill += i.typeService.getPrice() * i.numService;
    }
    
    getOrderList();
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\tTotal: " << _totalBill << endl; // thành tiền
    cout << "\t\t\tVAT: 10%" << endl;
    cout << "\t\t\tGrand total: " << 110/100 * _totalBill << endl; // tổng tiền thanh toán
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
} 

/*
* Class: ManageRoom
* Function: sort_room
* Description: This function is used for sorting ID of room
* Input:   None
* Output:  None
*/
void ManageRoom::sort_room() {
    roomList.sort();
}

/*
* Class: ManageRoom
* Function: getRoomList
* Description: This function is used for getting roomList (List of rooms)
* Input:   None
* Output:  return: roomList (List of rooms)
*/
list <Room> ManageRoom::getRoomList() {
    return roomList;
}

/*
* Class: ManageRoom
* Function: isFull
* Description: This function is used for check status of rooms
* Input:   None
* Output:  return: true (all of rooms is full)
           return: false (there is still room)
*/
bool ManageRoom::isFull() {
    for (auto it : roomList) {
        if (it.getStatus() == A) return false;
    }
    return true;
}

/*
* Class: ManageRoom
* Function: addRoom
* Description: This Function is used for adding a new room
* Input:   _roomID (ID of room)
* Output:  return: None
*/
void ManageRoom::addRoom(string _roomID) {
    Room newRoom;
    newRoom.setRoomID(_roomID);
    roomList.push_back(newRoom);
}

/*
* Class: ManageRoom
* Function: deleteRoom
* Description: This Function is used for deleting details of room
* Input:   _ID (ID of room)
* Output:  return: None
*/
void ManageRoom::deleteRoom(string _ID) {
    list<Room>::iterator it;
    for (it = roomList.begin(); it != roomList.end(); ++it) {
        if (it->getRoomID() == _ID) {
            cout << "\n-----------------------------------------Data is founded-----------------------------------------------" << endl << endl;
            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;

            cout << "\n\t\t\tAre you sure you want to delete this item?" << endl;
            int ans = 0;
            do {
                cout << "\t\t\t1. Yes" << endl;
                cout << "2. No" << endl;
                cout << "\t\t\tPlease Enter Your Choice: " << endl;
                cin >> ans;
                if (ans == 2) return;
            } while (ans != 1);
            roomList.erase(it);
        }
    }
}

/*
* Class: ManageRoom
* Function: showRoom
* Description: This function is used for displaying status of rooms
* Input:   None
* Output:  return: None
*/
void ManageRoom::showRoom() {
    sort_room();

    for (int floor = 1; floor <= 9; floor++) { 
        cout << "Floor " << floor << endl;   

        for (auto i : roomList) {
            if (i.getRoomID()[0] == floor) {
                cout << "\t\t" << i.getRoomID(); 
            }
        }
        cout << endl;

        for (auto i : roomList) {
            if (i.getRoomID()[0] == floor) {
                cout << "\t\t" << changeStatus(i.getStatus()); 
            }
        }   
        cout << endl << endl;
    }

    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\tU - Unavailable" << endl;
    cout << "\t\t\tA - Available";
}

/*
* Class: ManageRoom
* Function: getInfor
* Description: This function is used for displaying details of rooms
* Input:   _ID (ID of room)
* Output:  return: None
*/
void ManageRoom::getInfor(string _ID) {
    cout << "\n-----------------------------------------Customer Information------------------------------------------" << endl << endl;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;

    for (auto i : roomList) {
        if (i.getRoomID() == _ID) {
            for (auto j : i.getCustomerList()) {
                cout << "\tName: " << j.getNameCustomer() << endl;
                cout << "\tNumber phone: " << j.getPhoneCustomer() << endl << endl;

                cout << "\tCheckin-Checkout History: " << endl;
                cout << "\tTime\t\t\t" << "\t\t\tCheck in/out" << endl;
                cout << "\t" << j.getCheckIn().Time << "-" << j.getCheckIn().Date << "\t\t\tCheck in" << endl;
                cout << "\t" << j.getCheckOut().Time << "-" << j.getCheckOut().Date << "\t\t\tCheck out" << endl;
                cout << "\tFeedback: " << j.getFeedback() << endl;
                cout << "\n-------------------------------------------------------------------------------------------------------\n" << endl;
            }
        }
    }
}

/*
* Class: ManageRoom
* Function: menuManageRoom
* Description: This function is used for managing rooms of hotel
* Input:   None
* Output:  return: None
*/
void ManageRoom::menuManageRoom() {
menuManageRoom_start:
    int _choice = 0;
    cout << "\t\t\t-------------------------------" << endl;
    cout << "\t\t\t|     SERVICE MANAGEMENT     |" << endl;
    cout << "\t\t\t-------------------------------" << endl;
    do { 
        cout << "\t\t\t 1. Add Room" << endl; // 1. Thêm phòng
        cout << "\t\t\t 2. Delete Room" << endl; // 2. Xóa phòng
        cout << "\t\t\t 3. Room status" << endl; // 3. Xem trạng thái phòng
        cout << "\t\t\t 4. Turn Back Manager Menu" << endl; // 5. Thoát
        cout << "\t\t\t 5. Exit" << endl; // 5. Thoát
        cout << "\t\t\t............................" << endl;
        cout << "\t\t\tPlease Enter Your Choice: ";
        cin >> _choice;
    } while (_choice < 1 || _choice > 5);

    switch (_choice) {
    case 1:
    {
    add_room:
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "----------------------------------------------ROOM-----------------------------------------------------" << endl;
        showRoom();
        cout << endl << endl;

        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "----------------------------------------- Add room ------------------------------------------------" << endl;
        cout << "\t\t\tEnter ID of room you want: ";
        string _ID = ""; cin.ignore(); cin >> _ID;
        addRoom(_ID);
        cout << "\n----------------------------- Successfully Add New Employee Details -----------------------------------" << endl;

        do {
            cout << "\n\n\t\t\t 1. Continue Adding Another Room" << endl;
            cout << "\t\t\t 2. Turn Back Room Menu " << endl;
            cout << "\t\t\tPlease Enter Your Choice: ";
            cin >> _choice;
        } while (_choice != 1 && _choice != 2);

        if (_choice == 1) goto add_room;
        else goto menuManageRoom_start;

        break;
    }

    case 2:
    {
    delete_room:
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Delete Employee Detail ------------------------------------------" << endl;            
        cout << "\nEnter ID of room you want to delete: ";
        string _ID_input = 0; cin >> _ID_input;
        deleteRoom(_ID_input);
        cout << "\n---------------------------- Successfully Delete Employee Detail --------------------------------------" << endl;

        do {
            cout << "\n\n\t\t\t 1. Continue Deleting Another Room" << endl;
            cout << "\t\t\t 2. Turn Back Room Menu " << endl;
            cout << "\t\t\tPlease Enter Your Choice: ";
            cin >> _choice;
        } while (_choice != 1 && _choice != 2);

        if (_choice == 1) goto delete_room;
        else goto menuManageRoom_start;

        break;
    }

    case 3:
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "----------------------------------------------ROOM-----------------------------------------------------" << endl;
        showRoom();

        do {
            cout << "\n\n\t\t\t 1. Get room information" << endl;
            cout << "\t\t\t 2. Turn Back Room Menu " << endl;
            cout << "\t\t\tPlease Enter Your Choice: ";
            cin >> _choice;
        } while (_choice != 1 && _choice != 2);
        
        if (_choice == 1) {
            cout << "\t\t\tEnter ID of room you want: ";
            string _ID = ""; cin.ignore(); cin >> _ID;

            cout << "----------------------------------------------" << _ID << "-----------------------------------------------------" << endl << endl;
            getInfor(_ID);
        }

        else goto menuManageRoom_start;
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
}
