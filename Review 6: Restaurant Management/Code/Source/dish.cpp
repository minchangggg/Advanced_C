#include "dish.h"
using namespace std;

int Dish::getID() {
    return ID;
}

void Dish::setName(string _name) {
    name = _name;
}

string Dish::getName() {
    return name;
}

void Dish::setPrice(int _price) {
    price = _price;
}

int Dish::getPrice() {
    return price;
}

void Dish::setData() {
    cout << "\t\t\tEnter name of dish: ";
    string _name; 
    cin.ignore(); cin >> _name;
    setName(_name);

    cout << "\t\t\tEnter price of dish: ";
    int _price; cin >> _price;
    setPrice(_price);
}

void Dish::getData() {
    cout << "ID" << "\t\t\tName" << "\t\t\tPrice" << endl;
    cout << getID() << "\t\t\t" << getName() << "\t\t\t" << getPrice();
}
