/*
* File: cart.h
* Author: Ton Nu Minh Trang
* Date: 15/03/2024
* Description: This file is a cart header file that program is used for storing customer shopping cart's information
*/

#ifndef __CART_H
#define __CART_H

#include "storage.h"

int totalBill = 0;

using namespace std;

typedef enum {
    Cash,
    DebitCard,
    CreditCard,
    BankTransfer
} PaymentMethod; 

/*
*Class: Cart
*Description: This class contains basic properties and methods of a Cart object
*/

class Cart {
public:
    list <Product> shoppingCart;

    Cart() {}

    Product* searchByNameCart(string _name); 

    void add(string _name, int _num);
    void erase(string _name);

    void update(string _name, int _num);
    int checkNum(string _name);

    float calcBill();
    void getBill();
    void payment();
};

/*
*Class: Customer
*Description: This class contains basic properties and methods of a Customer object
*/

class Customer : public Cart {
private:
    int account;
    int password;
    PaymentMethod payment;

public:
    Customer() : Cart() {
        this->account = 123456789;
        this->password = 123456789;
        this->payment = Cash;
    }

    int getAccount();
    int getPassword();

    void paymentProgress();

    void menuCustom(); 
};

#endif
