#ifndef __PRODUCT_H
#define __PRODUCT_H

#include <bits/stdc++.h>
using namespace std;

class Product {
private:
    string name;
    float price;
    int ammount;

public:
    Product(string name = "temp", float price = 0, int ammount = 0) {
        this->name = name;
        this->price = price;
        this->ammount = ammount;
    }

    bool operator== (const Product& other) {
        return (name == other.name && price == other.price && ammount == other.ammount);
    }

    string getName() {
        return name;
    }

    float getPrice() {
        return price;
    }

    int getAmmount() {
        return ammount;
    }

    bool setName(string s) {
        name = s;
    }

    bool setPrice(float p) {
        price = p;
    }

    bool setAmmount(int am) {
        ammount = am;
    }

    bool increase() {
        ++ammount;
    }

    bool decrease() {
        if (ammount == 0) return false;

        --ammount;
        return true;
    }

    float getTotalPrice() {
        return price * ammount;
    }
};

#endif