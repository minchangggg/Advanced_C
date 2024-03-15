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

    void add(Product prod);
    void erase(Product prod);

    void decrease(Product prod, int ammount);
    void increase(Product prod, int ammount);

    void showStorage();

    void searchByName(string _name); 

    bool cmpName(const Product &a, const Product &b);
    bool cmpPrice(const Product &a, const Product &b);

    void sortName();
    void sortPrice();

} MainStorage;

#endif
