#ifndef _SERVICE_H
#define _SERVICE_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

class Service {
private:
    int serviceID;
    string name;
    int price;

public:
    Service() {
        static int _serviceID = 1;
        this->serviceID = _serviceID;
        _serviceID++;

        this->name = "";
        this->price= 0;
    }

    void setID (int _serviceID);
    int getID();

    void setName(string _name);
    string getName();

    void setPrice(int _price);
    int getPrice();

    void setData(string _name, int _price);   
};

class ManageService {
private:
    list <Service> dish; // 1. Đồ ăn, thức uống
    list <Service> pool; // 2. Bể bơi
    list <Service> gym; // 3. Gym
    list <Service> laundry; // 4. Giặt ủi

public:
    ManageService() {}
    
    list <Service> getDish();
    list <Service> getPool();
    list <Service> getGym();
    list <Service> getLaundry();

    // 1. Thêm món
    void addService(string _name, int _price, list <Service> &service);

    // 2. Xóa món
    void deleteService(int ID_input, list <Service> &service); 

    // 3. Danh sách món
    void showService(list <Service> &service); 

    // 4. Cập nhật giá món
    void editService(int ID_input, list <Service> &service); 

    // MENU
    void menuManageService();

};

#endif
