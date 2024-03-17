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
* Input:   _name (name of product), _price (price of product), _num (number of product) 
* Output:  return: None
*/
void Storage::add(string _name, int _price, int _num) { 
    Product newProd;
    newProd.setName(_name);
    newProd.setPrice(_price);
    newProd.setNum(_num);

    container.push_back(newProd);
}  

/*
* Class: Storage
* Function: searchByName
* Description: This function is used for searching product by name
* Input:   _name
* Output:  return: None
*/

bool Storage::searchByName(string _name) {
    list<Product>::iterator it;
    for (it = container.begin(); it != container.end(); ++it) {
        if (it->getName() == _name) return true;
        return false;
    }
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
        if (*it == prod) {
            unique_lock <mutex> lock(it->Prod_mtx);
            container.erase(it);
            return;
        }
    }
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
            (it->Prod_mtx).lock();
            it->setNum(it->getNum() - _num);
            (it->Prod_mtx).unlock();
            return;
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
            (it->Prod_mtx).lock();
            it->setNum(it->getNum() + _num);
            (it->Prod_mtx).unlock();
            return;
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
    cout << "\t\t\tNo" << "\t\t\tID" << "\t\t\tName" << "\t\t\tPrice" << "\t\t\tQuantiry" <<endl;
    cout << "________________________________________________________________________________________________________" << endl;

    list <Product>::iterator it;
    for (it = container.begin(); it != container.end(); ++it) {
        count++;
        shared_lock <mutex> lock(it->Prod_mtx);
        cout << "\t\t\t" << count << "\t\t\t" << it->getID() << "\t\t\t" << it->getName() << "\t\t\t" << it->getPrice() << "\t\t\t" << it->getNum() << endl;
        cout << "-------------------------------------------------------------------------------------------------------" << endl;
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
* Class: Storage
* Function: sortName
* Description: This function is used for sorting all of the products by name 
* Input:   None
* Output:  return: None
*/
void Storage::sortName() {
    container.sort(cmpName);
}

/*
* Class: Storage
* Function: sortPrice
* Description: This function is used for sorting all of the products by price 
* Input:   None
* Output:  return: None
*/
void Storage::sortPrice() {
    container.sort(cmpPrice);
}

/*
* Class: Administrator
* Function: getAccount
* Description: This function is used for getting administrator account
* Input:   None
* Output:  return: account (account of administrator)
*/
int Administrator::getAccount() {
    return account;
}

/*
* Class: Administrator
* Function: getPassword
* Description: This function is used for getting administrator password 
* Input:   None
* Output:  return: password (password of administrator)
*/
int Administrator::getPassword() {
    return password;
}

/*
* Class: Administrator
* Function: menuManager
* Description: This function is used for managing products of supermarket
* Input:   storage 
* Output:  return: None
*/

void Administrator::menuAdmin(Storage &storage) {
menuAdmin_start:
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
            goto menuAdmin_start;
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
            cout << "\t\t\t 1. Add New Product" << endl; // 1. Thêm món
            cout << "\t\t\t 2. Delete Product" << endl; // 2. Xóa món
            cout << "\t\t\t 3. Show Products" << endl; // 3. Danh sách món
            cout << "\t\t\t 4. Edit Products" << endl; // 4. Sửa món
            cout << "\t\t\t 5. Turn Back Main Menu" << endl; // 5. 	Quay lại
            cout << "\t\t\t 6. Exit program" << endl;
            cout << "\t\t\t............................" << endl;
            cout << "\t\t\tPlease Enter Your Choice: ";
            cin >> _choice;
        } while (_choice < 1 || _choice > 6);
      
        switch (_choice) {
        case 1:
        {
        add_product:
            cout << "\n\n--------------------------------------------- Menu ----------------------------------------------------" << endl;
            storage.showStorage();

            cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "------------------------------------------- Add -------------------------------------------------------" << endl;
            cout << "\t\t\tEnter the product name: ";
            string _name = ""; cin.ignore(); cin >> _name;

            cout << "\t\t\tEnter the price of the product: ";
            int _price = 0; cin >> _price;

            cout << "\t\t\tEnter the quantity of the product: ";
            int _num = 0; cin >> _num;
            
            storage.add(_name, _price, _num); 

            cout << "\n---------------------------------- Successfully Add Detail --------------------------------------------" << endl;

            do {
                cout << "\n\n\t\t\t 1. Continue adding another Dish " << endl;
                cout << "\n\t\t\t 2. Turn back Administration menu" << endl;
                cout << "\t\t\t 3. Exit program" << endl;
                cout << "\t\t\tPlease Enter Your Choice: ";
                cin >> _choice;

                if (_choice == 3) exit(0);

            } while (_choice != 1 && _choice != 2);

            if (_choice == 1) goto add_product;
            else goto menuAdmin_start;
            break;
        }

        case 2: 
        {
        erase_product:
            cout << "\n\n--------------------------------------------- Menu ----------------------------------------------------" << endl;
            storage.showStorage();

            cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "------------------------------------------- Delete ----------------------------------------------------" << endl;
            cout << "Enter the product name: ";
            string _name = ""; cin.ignore(); cin >> _name;

            try {
                if (storage.searchByName(_name)) {
                    cout << "\n------------------------------------------------------------------------------------------------------" << endl;
                    cout << "\n\t\t\tData is founded" << endl;
                    list <Product>::iterator it;
                    for (it = storage.container.begin(); it != storage.container.end(); ++it) {
                        if (it->getName() == _name) {
                            it->getProduct();
                            storage.erase(*it);
                        }
                    }
                    cout << "\n---------------------------------- Successfully Delete Detail -----------------------------------------" << endl;
                }
                else throw false;
            } 
            catch (bool earase) {
                cout << "\n------------------------------------------------------------------------------------------------------" << endl;
                cout << "\n\t\t\tNo product has this information" << endl;                   
            }

            do {
                cout << "\n\n\t\t\t 1. Continue erasing another product" << endl;
                cout << "\n\t\t\t 2. Turn back Administration menu" << endl;
                cout << "\t\t\t 3. Exit program" << endl;
                cout << "\t\t\tPlease Enter Your Choice: ";
                cin >> _choice;

                if (_choice == 3) exit(0);

            } while (_choice != 1 && _choice != 2);

            if (_choice == 1) goto erase_product;
            else goto menuAdmin_start;
            break;
        }

        case 3: 
        {
            cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "--------------------------------------------- Menu ----------------------------------------------------" << endl;
            storage.showStorage();
            
            do {
                cout << "\n\n\t\t\t 1. Turn back Administration menu" << endl;
                cout << "\t\t\t 2. Exit program" << endl;
                cout << "\t\t\tPlease Enter Your Choice: ";
                cin >> _choice;   
                
                if (_choice == 2) exit(0);

            } while (_choice != 1);

            goto menuAdmin_start;
            break;
        }

        case 4: 
        {
        edit_product:
            cout << "\n\n--------------------------------------------- Menu ----------------------------------------------------" << endl;
            storage.showStorage();

            cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "--------------------------------------------- Edit ----------------------------------------------------" << endl;
            cout << "Enter the product name: ";
            string _name = ""; cin.ignore(); cin >> _name;

            try {
                if (storage.searchByName(_name)) {
                    cout << "\n------------------------------------------------------------------------------------------------------" << endl;
                    cout << "\n\t\t\tData is founded" << endl;

                    list <Product>::iterator it;
                    for (it = storage.container.begin(); it != storage.container.end(); ++it) {
                        if (it->getName() == _name) it->getProduct();

                        cout << "Do you want to increase or decrease the quantity?" << endl;
                        do {
                            cout << "\t\t\t1. Increase" << endl;
                            cout << "\t\t\t2. Decrease" << endl; 
                            cout << "\t\t\t........................." << endl;
                            cout << "\t\t\tPlease Enter Your Choice: ";
                            cin >> _choice;
                        } while (_choice != 1 && _choice != 2);

                        cout << "Enter the quantity of product you want to edit: ";
                        int _num; cin >> _num;

                        if (_choice == 1) storage.increase(*it, _num);
                        else storage.decrease(*it, _num);
                        break;
                    }

                    cout << "\n---------------------------------- Successfully Edit Detail -------------------------------------------" << endl;
                }
                else throw false;
            } 
            catch (bool earase) {
                cout << "\n------------------------------------------------------------------------------------------------------" << endl;
                cout << "\n\t\t\tNo product has this information" << endl;                   
            }

            do {
                cout << "\n\n\t\t\t 1. Continue editing another product " << endl;
                cout << "\n\t\t\t 2. Turn back Administration menu" << endl;
                cout << "\t\t\t 3. Exit program" << endl;
                cout << "\t\t\tPlease Enter Your Choice: ";
                cin >> _choice;

                if (_choice == 3) exit(0);

            } while (_choice != 1 && _choice != 2);

            if (_choice == 1) goto edit_product;
            else goto menuAdmin_start;
            break;
        }

        case 5: 
            goto menuAdmin_start;
            break;

        case 6: 
        {
            cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "------------------------------------- Program Is Exit --------------------------------------------" << endl;
            exit(0);
            break;
        }

        default:
            break;  
        }
    
    }
}
