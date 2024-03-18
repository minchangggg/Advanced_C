/*
* File: product.cpp
* Author: Ton Nu Minh Trang
* Date: 15/03/2024
* Description: This file is a storage header file that program is used for storing Supermarket product's information
*/

#include "../Header/product.h"
using namespace std;

bool Product::operator== (const Product& other) {
    return (name == other.name && price == other.price && num == other.num);
}

/*
* Class: Product
* Function: getID
* Description: This function is used for getting ID of product 
* Input:   None
* Output:  return: ID (ID of product)
*/
int Product::getID() {
    return ID;
}

/*
* Class: Product
* Function: getName
* Description: This function is used for getting name of product
* Input:   None
* Output:  return: name (name of product)
*/
string Product::getName() const {
    return name;
}

/*
* Class: Product
* Function: getPrice
* Description: This function is used for getting price of product
* Input:   None
* Output:  return: price (price of product)
*/
float Product::getPrice() const {
    return price;
}

int Product::getNum() {
    return num;
}

/*
* Class: Product
* Function: getProduct
* Description: This function is used for getting data of product
* Input:   None
* Output:  return: None
*/
void Product::getProduct() {
    cout << "\t\t\tID" << "\t\t\tName" << "\t\t\tPrice" << "\t\t\tQuantity" << endl ;
    cout << "________________________________________________________________________________________________________" << endl;

    cout << "\t\t\t" << "\t\t\t" << getID() << "\t\t\t" << getName() << "\t\t\t" << getPrice() << endl;
    cout << "-------------------------------------------------------------------------------------------------------" << endl;
}

/*
* Class: Product
* Function: setID
* Description: This function is used for setting ID of product
* Input:   _ID (ID of product)
* Output:  return: None
*/
void Product::setID (int _ID) {
    ID = _ID;
}

/*
* Class: Product
* Function: setName
* Description: This function is used for setting name of product
* Input:   _name (name of product)
* Output:  return: None
*/
void Product::setName(string _name) {
    name = _name;
}

/*
* Class: Product
* Function: setPrice
* Description: This function is used for setting price of product
* Input:   _price (price of product)
* Output:  return: None
*/
void Product::setPrice(float _price) {
    price = _price;
}

/*
* Class: Product
* Function: setNum
* Description: This function is used for setting number of product
* Input:   _num (number of product)
* Output:  return: None
*/
void Product::setNum(int _num) {
    num = _num;
}

/*
* Class: Product
* Function: increase
* Description: This function is used for increasing number of product
* Input:   None
* Output:  return: None
*/
void Product::increase() {
    ++num;
}

/*
* Class: Product
* Function: decrease
* Description: This function is used for decreasing number of product
* Input:   None
* Output:  return: true || false
*/
bool Product::decrease() {
    if (num == 0) return false;

    --num;
    return true;
}
