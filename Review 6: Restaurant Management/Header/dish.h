#ifndef _DISH_H
#define _DISH_H

#include <iostream>
#include <string>

using namespace std;

class Dish {
private:
    short int ID;
    string name;
    int price;

public:
    Dish() {
        this->ID = 0;
        this->name = "";
        this->price= 0;
    }

    void setID(short int _ID);
    short int getID();

    void setName(string _name);
    string getName();

    void setPrice(int _price);
    int getPrice();

    void setData();
    void getData();
};

typedef struct {
    int num;
    Dish dish;
} Order;

#endif
