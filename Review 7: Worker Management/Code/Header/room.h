#ifndef _ROOM_H
#define _ROOM_H

#include "service.h"

using namespace std;

typedef struct {
    string Time;
    string Date;
} CheckTime;

typedef struct {
    Service typeService; 
    int numService;
} Order;

class Customer {
private:
    string nameCustomer;
    int phoneCustomer;
    CheckTime checkIn;
    CheckTime checkOut;
    string feedback;

public:
    Customer() {}

    void setNameCustomer(string _name);
    string getNameCustomer();

    void setPhoneCustomer(int _phone);
    int getPhoneCustomer();

    void setCheckIn (CheckTime _checkIn);
    void setCheckOut (CheckTime _checkOut);

    CheckTime getCheckIn();
    CheckTime getCheckOut();

    void setFeedback(string _feedback);
    string getFeedback();
};

typedef enum { 
    U, // Unavailable
    A // Available
} Status;

string changeStatus(Status _status) {
    string status = "";
    if (_status == U) status = "U";
    else if (_status == A) status = "A";

    return status; 
}

class Room {
private:
    string roomID; // ID phòng 
    Status status;
    list<Order> orderService;
    int totalBill;

    list<Customer> customerList;

public:
    Room() {
        this->roomID = "";
        status = A;
    }

    list<Order> getOrderService();
    list<Customer> getCustomerList();

    void setRoomID(string _roomID);
    string getRoomID() const;

    void setStatus(Status _status);
    Status getStatus();

    void getRoom();
    void resetTable();

    void addOrder(ManageService manageService);
    void getOrderList();
    void getBill();
};

class ManageRoom {
private:
    list <Room> roomList;

public:
    ManageRoom() {}

    list <Room> getRoomList();
    bool isFull();

    void addRoom(string _roomID);// Thêm phòng
    void deleteRoom(string _ID); // Xóa phòng

    bool cmpName(const Room &a, const Room &b) {
        return a.getRoomID() < b.getRoomID();  
    }
    void sort_room(list <Room> &room) {
        room.sort(cmpName);
    }

    void showRoom(); 
    void getInfor(string _ID); // Xem trạng thái phòng

    void menuManageRoom(); // MENU
};

#endif
