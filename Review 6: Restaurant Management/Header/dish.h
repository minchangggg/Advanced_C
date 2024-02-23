#ifndef _DISH_H
#define _DISH_H

#include <iostream>
#include <string>

using namespace std;

class Dish {
private:
    int ID;
    string name;
    int price;

public:
    Dish() {
        static int _ID = 1;
        this->ID = _ID;
        _ID++;

        this->name = "";
        this->price= 0;
    }
    
    int getID();

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
