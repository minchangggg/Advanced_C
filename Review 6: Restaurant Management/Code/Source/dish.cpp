/*
* File: dish.cpp
* Author: Ton Nu Minh Trang
* Date: 10/02/2024
* Description: This file contains all the functions/methods to store dish's information
*/

#include "../Header/dish.h"
using namespace std;

/*
* Class: Dish
* Function: setID
* Description: This function is used for setting ID of dish
* Input:   _ID (ID of dish)
* Output:  return: None
*/
void Dish::setID (int _ID) {
    ID = _ID;
}

/*
* Class: Dish
* Function: getID
* Description: This function is used for getting ID of dish
* Input:   None
* Output:  return: ID (ID of dish)
*/
int Dish::getID() {
    return ID;
}

/*
* Class: Dish
* Function: setName
* Description: This function is used for setting name of dish
* Input:   _name (name of dish)
* Output:  return: None
*/
void Dish::setName(string _name) {
    name = _name;
}

/*
* Class: Dish
* Function: getName
* Description: This function is used for getting name of dish
* Input:   None
* Output:  return: name (name of dish)
*/
string Dish::getName() {
    return name;
}

/*
* Class: Dish
* Function: setPrice
* Description: This function is used for setting price of dish
* Input:   _price (price of dish)
* Output:  return: None
*/
void Dish::setPrice(int _price) {
    price = _price;
}

/*
* Class: Dish
* Function: getPrice
* Description: This function is used for getting price of dish
* Input:   None
* Output:  return: price (price of dish)
*/
int Dish::getPrice() {
    return price;
}

/*
* Class: Dish
* Function: setData
* Description: This function is used for setting data of dish
* Input:   None
* Output:  return: None
*/
void Dish::setData() {
    cout << "\t\t\tEnter name of dish: ";
    string _name; 
    cin.ignore(); cin >> _name;
    setName(_name);

    cout << "\t\t\tEnter price of dish: ";
    int _price; cin >> _price;
    setPrice(_price);
}

/*
* Class: Dish
* Function: getData
* Description: This function is used for getting data of dish
* Input:   None
* Output:  return: None
*/
void Dish::getData() {
    cout << "ID" << "\t\t\tName" << "\t\t\tPrice" << endl;
    cout << getID() << "\t\t\t" << getName() << "\t\t\t" << getPrice();
}
