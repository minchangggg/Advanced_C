/*
* File: storage.cpp
* Author: Ton Nu Minh Trang
* Date: 15/03/2024
* Description: This file contains all the functions/methods to store all of the Supermarket products's information
*/

#include "../Header/storage.h"
using namespace std;

/*
* Class: Storage
* Function: add
* Description: This Function is used for adding a new product
* Input:   prod 
* Output:  return: None
*/
void Storage::add(Product prod) { 
    container.push_back(prod);
}

/*
* Class: Storage
* Function: erase
* Description: This Function is used for erasing a new product
* Input:   prod
* Output:  return: None
*/
void Storage::erase(Product prod) {
    list <Product>::iterator it;
    for (it = container.begin(); it != container.end(); ++it) {
        if (*it == prod) break;
    }

    container.erase(it);
}

/*
* Class: Storage
* Function: decrease
* Description: This function is used for decreasing number of product in shopping cart
* Input:   prod and _num
* Output:  return: None
*/
void Storage::decrease(Product prod, int _num) {
    list <Product>::iterator it;
    for (it = container.begin(); it != container.end(); ++it) {
        if (*it == prod) {
            it->setNum(it->getNum() - _num);
            break;
        }
    }
}

/*
* Class: Storage
* Function: increase
* Description: This function is used for increasing number of product in shopping cart
* Input:   prod and _num
* Output:  return: None
*/
void Storage::increase(Product prod, int _num) {
    list <Product>::iterator it;
    for (it = container.begin(); it != container.end(); ++it) {
        if (*it == prod) {
            it->setNum(it->getNum() + _num);
            break;
        }
    }
}

/*
* Class: Storage
* Function: showStorage
* Description: This function is used for showing storage of supermarket
* Input:   None
* Output:  return: None
*/
void Storage::showStorage() {
    int count = 0;
    cout << "\t\t\tNo" << "\t\t\tID" << "\t\t\tName" << "\t\t\tPrice" <<endl;
    cout << "________________________________________________________________________________________________________" << endl;

    for (auto i : container) {
        count++;
        cout << "\t\t\t" << count << "\t\t\t" << i.getID() << "\t\t\t" << i.getName() << "\t\t\t" << i.getPrice() << endl;
        cout << "-------------------------------------------------------------------------------------------------------" << endl;
    }
}

/*
* Class: Storage
* Function: searchByName
* Description: This function is used for searching product by name
* Input:   _name
* Output:  return: None
*/
void Storage::searchByName(string _name) {
    list<Product>::iterator it;
    for (it = container.begin(); it != container.end(); ++it) {
        if (it->getName() == _name) {
            cout << "\n\t\t\tData is founded " << endl;
            it->getProduct();
            return;
        }
        cout << "\n\t\t\t No product has this information " << endl;
    }
}

/*
* Class: Storage
* Function: cmpName
* Description: This function is used for sorting two products by name
* Input:   a (1st student), b (2nd student)
* Output:  return: b (2nd student)
*/
bool Storage::cmpName(const Product &a, const Product &b) {
    return a.getName() < b.getName();
}

/*
* Class: Storage
* Function: cmpPrice
* Description: This function is used for sorting two products by price
* Input:   a (1st product), b (2nd product)
* Output:  return: b (2nd product)
*/
bool Storage::cmpPrice(const Product &a, const Product &b) {
    return a.getPrice() < b.getPrice();
}

/*
* Function: sortName
* Description: This function is used for sorting all of the products by name 
* Input:   None
* Output:  return: None
*/
void Storage::sortName() {
    container.sort(cmpName);
}

/*
* Function: sortPrice
* Description: This function is used for sorting all of the products by price 
* Input:   None
* Output:  return: None
*/
void Storage::sortPrice() {
    container.sort(cmpPrice);
}
