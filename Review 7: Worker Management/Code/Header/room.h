#ifndef _ROOM_H
#define _ROOM_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

typedef struct {
    string Time;
    string Date;
} CheckTime;

class Customer {
private:
    string name;
    int phone;
    CheckTime checkIn;
    CheckTime checkOut;
    string feedback;

public:
    Customer() {}

    void setName(string _name);
    string getName();

    void setPhone(int _phone);
    int getPhone();

    void setCheckIn (CheckTime _checkIn);
    void setCheckOut (CheckTime _checkOut);

    CheckTime getCheckIn();
    CheckTime getCheckOut();

    void setFeedback(string _feedback);
    string getFeedback();
};

typedef enum { 
    U, // Unavailable
    A, // Available
    C  // Cleaning
} Status;

string changeStatus(Status _status) {
    string status = "";
    if (_status == U) status = "U";
    else if (_status == A) status = "A";
    else if (_status == C) status = "C";

    return status; 
}

class Room {
private:
    string roomID; // ID phòng 
    Status status;
    list<Customer> customerList;

public:
    Room() {
        this->roomID = "";
        status = A;
    }

    list<Customer> getCustomerList();

    void setID(string _roomID);
    string getID() const;

    void setStatus(Status _status);
    Status getStatus();

};

class ManageRoom {
private:
    list <Room> roomList;

public:
    ManageRoom() {}
    void addRoom(string _roomID);// Thêm phòng
    void deleteRoom(string _ID); // Xóa phòng

    bool cmpName(const Room &a, const Room &b) {
        return a.getID() < b.getID();  
    }
    void sort_room(list <Room> &room) {
        room.sort(cmpName);
    }

    void showRoom(); 
    void getInfor(string _ID); // Xem trạng thái phòng

    void menuManageRoom(); // MENU
};

#endif
