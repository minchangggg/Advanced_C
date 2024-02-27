#include "../Header/room.h"
using namespace std;

void Customer::setName(string _name) {
    name = _name;
}

string Customer::getName() {
    return name;
}

void Customer::setPhone(int _phone) {
    phone = _phone;
}

int Customer::getPhone() {
    return phone;
}

void Customer::setCheckIn (CheckTime _checkIn) {
    checkIn = _checkIn;
}

void Customer::setCheckOut (CheckTime _checkOut) {
    checkOut = _checkOut;
}

CheckTime Customer::getCheckIn() {
    return checkIn;
}

CheckTime Customer::getCheckOut() {
    return checkOut;
}

void Customer::setFeedback(string _feedback) {
    feedback = _feedback;
}

string Customer::getFeedback() {
    return feedback;
}

//___________________________________________________________________________________________________
    
list<Customer> Room::getCustomerList() {
    return customerList;
}

void Room::setID(string _roomID) {
    roomID = _roomID;
}

string Room::getID() const {
    return roomID;
}

void Room::setStatus(Status _status) {
    status = _status;
}

Status Room::getStatus() {
    return status;
}

//___________________________________________________________________________________________________

void ManageRoom::addRoom(string _roomID) {
    Room newRoom;
    newRoom.setID(_roomID);
    roomList.push_back(newRoom);
}

void ManageRoom::deleteRoom(string _ID) {
    list<Room>::iterator it;
    for (it = roomList.begin(); it != roomList.end(); ++it) {
        if (it->getID() == _ID) {
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

void ManageRoom::showRoom() {
    sort_room(roomList);

    for (int floor = 1; floor <= 9; floor++) { 
        cout << "Floor " << floor << endl;   

        for (auto i : roomList) {
            if (i.getID()[0] == floor) {
                cout << "\t\t" << i.getID(); 
            }
        }

        for (auto i : roomList) {
            if (i.getID()[0] == floor) {
                cout << "\t\t" << changeStatus(i.getStatus()); 
            }
        }        
    }
}

void ManageRoom::getInfor(string _ID) {
    cout << "\n-----------------------------------------Customer Information------------------------------------------" << endl << endl;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;

    for (auto i : roomList) {
        if (i.getID() == _ID) {
            for (auto j : i.getCustomerList()) {
                cout << "\tName: " << j.getName() << endl;
                cout << "\tNumber phone: " << j.getPhone() << endl << endl;

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

void ManageRoom::menuManageRoom() {
menuManageRoom_start:
    int _choice = 0;
    cout << "\t\t\t-------------------------------" << endl;
    cout << "\t\t\t|     SERVICE MANAGEMENT     |" << endl;
    cout << "\t\t\t-------------------------------" << endl;
    do { 
        cout << "\t\t\t 1. Add room" << endl; // 1. Thêm phòng
        cout << "\t\t\t 2. Delete room" << endl; // 2. Xóa phòng
        cout << "\t\t\t 3. Room status" << endl; // 3. Xem trạng thái phòng
        cout << "\t\t\t 4. Exit" << endl; // 5. Thoát
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
        cout << endl << endl;

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

    default:
        break;
    }
}
