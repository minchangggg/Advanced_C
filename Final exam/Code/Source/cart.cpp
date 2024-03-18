/*
* File: cart.cpp
* Author: Ton Nu Minh Trang
* Date: 15/03/2024
* Description: This file contains all the functions/methods to store customer shopping cart's information
*/

#include "../Header/cart.h"
using namespace std;

/*
* Class: Cart
* Function: searchByName
* Description: This function is used for searching product by name in shopping Cart
* Input:   _name
* Output:  return: None
*/
Product* Cart::searchByName(string _name) {
    list<Product>::iterator it;
    for (it = shoppingCart.begin(); it != shoppingCart.end(); ++it) {
        if (it->getName() == _name) return &(*it);
    }
    return NULL;
}

/*
* Class: Cart
* Function: add
* Description: This Function is used for adding a product to cart
* Input:   _name (name of product)
* Output:  return: None
*/
void Cart::add(string _name) {
    try {
        if (MainStorage.searchByName(_name) != NULL) {
            cout << "\n------------------------------------------------------------------------------------------------------" << endl;
            MainStorage.searchByName(_name)->getProduct();

            try {
                if (!MainStorage.isEmpty(_name)) {
                    MainStorage.decrease(_name, 1); // trừ đi 1 sản phẩm khỏi kho 
                    shoppingCart.push_back(*MainStorage.searchByName(_name));
                    cout << "\n---------------------------------- Successfully Add Detail -------------------------------------------" << endl;
                }
                else throw false;
            } catch (bool exception) {
                cout << "This product is out of stock. Please choose another product." << endl;
            }
        }
        else throw false;
    } catch (bool exception) {
        cout << "Product name does not exist. Please choose another product." << endl;
    }
}

/*
* Class: Cart
* Function: erase
* Description: This Function is used for erasing a product from cart
* Input:   _name (name of product)
* Output:  return: None
*/
void Cart::erase(string _name) {
    list <Product>::iterator it;
    for (it = shoppingCart.begin(); it != shoppingCart.end(); ++it) {
        if (it->getName() == _name) {
            MainStorage.increase(_name, it->getNum()); // thêm vào lại số sản phẩm có trong giỏ
            shoppingCart.erase(it); // xóa sản phẩm ở giỏ hàng
            return;
        }
    }
}

/*
* Class: Cart
* Function: update
* Description: This Function is used for updating product detail in cart
* Input:   _name (name of product), _num (num of product)
* Output:  return: None
*/
void Cart::update(string _name, int _num) {
    if (_num == 0) erase(_name); // TH1: nếu num nhập vào = 0 thì xóa sp 

    else if (_num > checkNum(_name)) { // TH2: nếu num nhập vào > số lượng sản phẩm còn trong kho
        if (_num < searchByName(_name)->getNum()) { 
            MainStorage.increase(_name, (searchByName(_name)->getNum())-(_num)); // nếu mà lượng sp nhập vào < lượng sp ban đầu -> ng dùng giảm số lượng sp -> cộng phần dư vào lại storage
            searchByName(_name)->setNum(_num); 
        }  
        else cout << "It is an invalid quantity value." << endl; // nếu ko đủ lượng sp thì thông báo lỗi
    }

    else { // TH3: nếu num nhập vào < số lượng sản phẩm trong kho
        if (_num < searchByName(_name)->getNum()) { 
            MainStorage.increase(_name, (searchByName(_name)->getNum())-(_num)); // nếu mà lượng sp nhập vào < lượng sp ban đầu -> ng dùng giảm số lượng sp -> cộng phần dư vào lại storage
            searchByName(_name)->setNum(_num); 
        }  
        else if (_num > searchByName(_name)->getNum()) {
            MainStorage.decrease(_name, (_num)-(searchByName(_name)->getNum())); // nếu mà lượng sp nhập vào < lượng sp ban đầu -> ng dùng giảm số lượng sp -> cộng phần dư vào lại storage
            searchByName(_name)->setNum(_num);             
        }
        else cout << "Product quantity does not change" << endl;
    }
}

/*
* Class: Cart
* Function: checkNum
* Description: This Function is used for checking number of product in storage
* Input:   _name (name of product)
* Output:  return: None
*/
int Cart::checkNum(string _name) {
    list <Product>::iterator it;
    for (it = MainStorage.container.begin(); it != MainStorage.container.end(); ++it) {
        if (it->getName() == _name) return it->getNum();
    }
}

/*
* Class: Cart
* Function: calcBill
* Description: This Function is used for calculating bill of storage
* Input:   None
* Output:  return: totalBill
*/
float Cart::calcBill() {
    int totalBill = 0;
    for (auto &i : shoppingCart) {
        totalBill += i.getPrice() * i.getNum();
    }
    return totalBill;
}

/*
* Class: Cart
* Function: getBill
* Description: This Function is used for print bill of storage
* Input:   None
* Output:  return: None
*/
void Cart::getBill() { 
    future <float> resultFuture = async(launch::async, calcBill);

    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\tTotal: " << resultFuture.get() << endl; 
    cout << "\t\t\tVAT: 10%" << endl;
    cout << "\t\t\tGrand total: " << 110/100 * resultFuture.get() << endl; 
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
} 

void Cart::payment() {
    //
}

/*
* Class: Customer
* Function: getAccount
* Description: This function is used for getting customer account
* Input:   None
* Output:  return: account (account of administrator)
*/
int Customer::getAccount() {
    return account;
}

/*
* Class: Customer
* Function: getPassword
* Description: This function is used for getting customer password 
* Input:   None
* Output:  return: password (password of administrator)
*/
int Customer::getPassword() {
    return password;
}

/*
* Class: Customer
* Function: menuCustom
* Description: This function is used for managing cart 
* Input:   storage 
* Output:  return: None
*/
void Customer::menuCustom() {
menuCustom_start:
    int _password = 0; int _account = 0; int _choice = 0; 

    cout << "\t\t\t\t\t\tLOG IN" << endl;

    cout << "\t\t\tPlease Enter Account / Phone number: ";
    cin >> _account;
 
    cout << "\t\t\tPlease Enter Password: ";
    cin >> _password;

    if ((getAccount() != _account) || (getPassword() != _password)) {
        cout << "\n\n\t\t\tThe Password Is Incorrect!" << endl;
        cout << "\t\t\t-------------------------" << endl;
        cout << "\t\t\t1. Re-enter The Password" << endl;
        cout << "\t\t\t2. Turn Back Main Menu " << endl;
        cout << "\t\t\t3. Exit Program" << endl;
        cout << "\t\t\tPlease Enter Your Choice: ";
        cin >> _choice;

        switch (_choice) {
        case 1:
            goto menuCustom_start;
            break;

        case 2:
            break;

        case 3:
            cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "------------------------------------- Program Is Exit --------------------------------------------" << endl;
            exit(0);
            break;

        default:
            break;
        }
    }

    else if((getAccount() == _account) && (getPassword() == _password)) {
        cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "--------------------------------------Administration menu----------------------------------------------" << endl;            
        do { 
            cout << "\t\t\t 1. Show Products In Cart" << endl; 
            cout << "\t\t\t 2. Add Product Add To Cart" << endl; 
            cout << "\t\t\t 3. Remove Product From Cart" << endl; 
            cout << "\t\t\t 4. Edit Product" << endl;
            cout << "\t\t\t 5. Turn Back Main Menu" << endl; 
            cout << "\t\t\t 6. Exit program" << endl;
            cout << "\t\t\t............................" << endl;
            cout << "\t\t\tPlease Enter Your Choice: ";
            cin >> _choice;
        } while (_choice < 1 || _choice > 6);
        // code
}
