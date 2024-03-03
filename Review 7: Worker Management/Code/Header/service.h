/*
* File: service.h
* Author: Ton Nu Minh Trang
* Date: 15/02/2024
* Description: This file is a Service header file which manages types of services of hotel
*/

#ifndef _SERVICE_H
#define _SERVICE_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

/*
*Class: Service
*Description: This class contains basic properties and methods of a Service object
*/
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

/*
*Class: ManageEmployee
*Description: This class contains basic properties and methods that manage types of services of hotel
*/
class ManageService {
private:
    list <Service> dish;
    list <Service> pool;
    list <Service> gym;
    list <Service> laundry; 

public:
    ManageService() {}
    
    list <Service> getDish();
    list <Service> getPool();
    list <Service> getGym();
    list <Service> getLaundry();

    void addService(string _name, int _price, list <Service> &service);
    void deleteService(int ID_input, list <Service> &service); 
    void showService(list <Service> service); 
    void editService(int ID_input, list <Service> &service); 

    void menuManageService();
};

#endif
