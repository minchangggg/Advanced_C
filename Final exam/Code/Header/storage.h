/*
* File: storage.h
* Author: Ton Nu Minh Trang
* Date: 15/03/2024
* Description: This file is a storage header file that program is used for storing all of the Supermarket products's information
*/

#ifndef __STORAGE_H
#define __STORAGE_H

#include <product.h>
using namespace std;

/*
*Class: Storage
*Description: This class contains basic properties and methods of a Storage object
*/

class Storage {
public:
    list <Product> container;

    Storage() {}

    void add(string _name, int _price, int _num);

    Product* searchByName(string _name); 

    void erase(string _name);
    
    void showStorage(); 

    void decrease(string _name, int _num);
    void increase(string _name, int _num);
    bool checkNum(string _name);

    bool cmpName(const Product &a, const Product &b);
    bool cmpPrice(const Product &a, const Product &b);

    void sortName();
    void sortPrice();

} MainStorage;

/*
*Class: Administrator
*Description: This class contains basic properties and methods of a Administrator object
*/

class Administrator {
private:
    int account;
    int password;

public:
    Administrator() {
        this->account = 123456789;
        this->password = 123456789;
    }

    int getAccount();
    int getPassword();
    
    void menuAdmin();
};

#endif
