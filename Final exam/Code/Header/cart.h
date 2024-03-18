/*
* File: cart.h
* Author: Ton Nu Minh Trang
* Date: 15/03/2024
* Description: This file is a cart header file that program is used for storing customer shopping cart's information
*/

#ifndef __CART_H
#define __CART_H

#include "storage.h"

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

class Cart : public Storage {
public:
    list <Product> shoppingCart;

    Cart() : Storage() {}

    Product* searchByName(string _name); 

    void add(string _name);
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

class Customer {
private:
    int account;
    int password;
    PaymentMethod payment;

public:
    Customer() {
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
