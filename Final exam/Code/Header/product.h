/*
* File: product.h
* Author: Ton Nu Minh Trang
* Date: 15/03/2024
* Description: This file is a product header file that program is used for storing Supermarket product's information
*/

#ifndef __PRODUCT_H
#define __PRODUCT_H

#include <bits/stdc++.h>
using namespace std;

/*
*Class: Product
*Description: This class contains basic properties and methods of a Product object
*/

class Product {
private:
    int ID;
    string name;
    float price;
    int num;

public:
    mutex Prod_mtx;

    Product() {
        static int _ID = 0;
        this->ID = _ID;
        _ID++;

        this->name = "";
        this->price = 0;
        this->num = 0;
    }

    bool operator== (const Product& other);

    int getID();
    string getName() const;
    float getPrice() const;
    int getNum();
    void getProduct();

    void setID (int _ID);
    void setName(string _name);
    void setPrice(float _price);
    void setNum(int _num);

    void increase();
    bool decrease();
    
};

#endif
