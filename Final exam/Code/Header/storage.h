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

    bool searchByName(string _name); 

    void erase(Product prod);
    
    void showStorage();

    void decrease(Product prod, int ammount);
    void increase(Product prod, int ammount);

    bool cmpName(const Product &a, const Product &b);
    bool cmpPrice(const Product &a, const Product &b);

    void sortName();
    void sortPrice();

} MainStorage;

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
    
    void menuAdmin(Storage &storage);
};

#endif