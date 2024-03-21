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
Product* Cart::searchByNameCart(string _name) {
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
void Cart::add(string _name, int _num) {
    try {
        if (MainStorage.searchByName(_name) != NULL) {
            cout << "\n------------------------------------------------------------------------------------------------------" << endl;
            MainStorage.searchByName(_name)->getProduct();

            try {
                if (!MainStorage.isEmpty(_name)) {
                    Product _product;
                    _product.setID(MainStorage.searchByName(_name)->getID());
                    _product.setName(MainStorage.searchByName(_name)->getName());
                    _product.setNum(_num);
                    _product.setPrice(MainStorage.searchByName(_name)->getPrice());

                    shoppingCart.push_back(_product);

                    MainStorage.decrease(_name, _num); 

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
* Function: showCart
* Description: This function is used for showing storage of supermarket
* Input:   None
* Output:  return: None
*/
void Cart::showCart(){
    int count = 0;
    cout << "\t\t\tNo" << "\t\t\tID" << "\t\t\tName" << "\t\t\tPrice" << "\t\t\tQuantity" <<endl;
    cout << "________________________________________________________________________________________________________" << endl;

    list <Product>::iterator it;
    for (it = MainCart.shoppingCart.begin(); it != MainCart.shoppingCart.end(); ++it) {
        count++;
        cout << "\t\t\t" << count << "\t\t\t" << it->getID() << "\t\t\t" << it->getName() << "\t\t\t" << it->getPrice() << "\t\t\t" << it->getNum() << endl;
        cout << "-------------------------------------------------------------------------------------------------------" << endl;
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
        if (_num < MainStorage.searchByName(_name)->getNum()) { 
            MainStorage.increase(_name, (MainStorage.searchByName(_name)->getNum())-(_num)); // nếu mà lượng sp nhập vào < lượng sp ban đầu -> ng dùng giảm số lượng sp -> cộng phần dư vào lại storage
            searchByNameCart(_name)->setNum(_num); 
        }  
        else cout << "It is an invalid quantity value." << endl; // nếu ko đủ lượng sp thì thông báo lỗi
    }

    else { // TH3: nếu num nhập vào < số lượng sản phẩm trong kho
        if (_num < MainStorage.searchByName(_name)->getNum()) { 
            MainStorage.increase(_name, (MainStorage.searchByName(_name)->getNum())-(_num)); // nếu mà lượng sp nhập vào < lượng sp ban đầu -> ng dùng giảm số lượng sp -> cộng phần dư vào lại storage
            searchByNameCart(_name)->setNum(_num); 
        }  
        else if (_num > MainStorage.searchByName(_name)->getNum()) {
            MainStorage.decrease(_name, (_num)-(MainStorage.searchByName(_name)->getNum())); // nếu mà lượng sp nhập vào < lượng sp ban đầu -> ng dùng giảm số lượng sp -> cộng phần dư vào lại storage
            searchByNameCart(_name)->setNum(_num);             
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
    if (shoppingCart.empty()) totalBill = 0;
    else {
        for (auto &i : shoppingCart) {
            totalBill += i.getPrice() * i.getNum();
        }
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
    // future <float> resultFuture = async(launch::async, calcBill());

    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    // cout << "\t\t\tTotal: " << resultFuture.get() << endl; 
    cout << "\t\t\tTotal: " << calcBill() << endl; 
    cout << "\t\t\tVAT: 10%" << endl;
    cout << "\t\t\tGrand total: " << 110/100 * calcBill() << endl; 
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
} 

/*
* Class: Cart
* Function: payment
* Description: This Function is used for print bill of storage
* Input:   None
* Output:  return: None
*/
void Cart::getMethod(PaymentMethod method) {
    switch (method) {
    case Cash:
        // 
        break;

    case DebitCard:
        //
        break;

    case CreditCard:
        //
        break;

    case BankTransfer:
        //
        break;

    default:
        break;
    }
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
    string _name = ""; int _price = 0; int _num = 0;
    
    // Storage _shoppingCart;
    // _shoppingCart.container = MainCart.shoppingCart;

    thread threadAddCart(&Cart::add, _name, _num, &MainCart);
    thread threadEraseCart(&Cart::erase, _name, &MainCart);

    thread threadUpdate(&Cart::update, _name, _num, &MainCart);
    thread threadCheckNum(&Cart::checkNum, _name, &MainCart);

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
            cout << "\t\t\t 5. Confirm Payment" << endl; 
            cout << "\t\t\t 6. Turn Back Main Menu" << endl;
            cout << "\t\t\t 7. Exit program" << endl;
            cout << "\t\t\t............................" << endl;
            cout << "\t\t\tPlease Enter Your Choice: ";
            cin >> _choice;
        } while (_choice < 1 || _choice > 6);

        switch (_choice) {

        case 1: 
        {
            cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "-----------------------------------------List of Product ----------------------------------------------" << endl << endl;
            MainStorage.showStorage();

            do {
                cout << "\t\t\t 1. Sort by name" << endl;
                cout << "\t\t\t 2. Sort by price" << endl;
                cout << "\t\t\t Please Enter Your Choice: ";
                cin >> _choice;
            } while (_choice != 1 && _choice != 2);
            cout << "-------------------------------------------------------------------------------------------------------" << endl;

            if (_choice == 1) MainStorage.sortName();
            else MainStorage.sortPrice();

            do {
                cout << "\n\t\t\t 1. Turn back Customer menu" << endl;
                cout << "\t\t\t 2. Exit program" << endl;
                cout << "\t\t\t Please Enter Your Choice: ";
                cin >> _choice;   
                
                if (_choice == 2) exit(0);

            } while (_choice != 1);

            goto menuCustom_start;
            break;
        }

        case 2:
        {
        add_cart:
            cout << "\n\n-----------------------------------------List of Product ----------------------------------------------" << endl;
            MainStorage.showStorage();

            cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "------------------------------------------- Add -------------------------------------------------------" << endl;
            cout << "\t\t\tEnter the product name: ";
            cin.ignore(); cin >> _name;

            cout << "\t\t\tEnter the quantity of the product: ";
            cin >> _num;
            
            MainCart.add(_name, _num); 

            cout << "\n---------------------------------- Successfully Add Detail --------------------------------------------" << endl << endl;

            do {
                cout << "\t\t\t 1. Continue adding another product" << endl;
                cout << "\t\t\t 2. Turn back Customer menu" << endl;
                cout << "\t\t\t 3. Exit program" << endl;
                cout << "\t\t\t Please Enter Your Choice: ";
                cin >> _choice;

                if (_choice == 3) exit(0);

            } while (_choice != 1 && _choice != 2);

            if (_choice == 1) goto add_cart;
            else goto menuCustom_start;
            break;
        }

        case 3: 
        {
        remove_cart:
            cout << "\n\n-------------------------------------------- My Cart --------------------------------------------------" << endl;
            MainCart.showCart();

            cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "------------------------------------------- Delete ----------------------------------------------------" << endl;
            cout << "Enter the product name: ";
            cin.ignore(); cin >> _name;

            try {
                if (MainCart.searchByNameCart(_name) != NULL) {
                    cout << "\n------------------------------------------------------------------------------------------------------" << endl;
                    cout << "\n\t\t\tData is founded" << endl;
                    MainCart.searchByNameCart(_name)->getProduct();
                    MainCart.erase(_name);
                    cout << "\n---------------------------------- Successfully Delete Detail -----------------------------------------" << endl;
                }
                else throw false;
            } 
            catch (bool earase) {
                cout << "\n------------------------------------------------------------------------------------------------------" << endl << endl;
                cout << "\n\t\t\tNo product has this information" << endl;                   
            }

            do {
                cout << "\t\t\t 1. Continue erasing another product" << endl;
                cout << "\t\t\t 2. Turn back Customer menu" << endl;
                cout << "\t\t\t 3. Exit program" << endl;
                cout << "\t\t\t Please Enter Your Choice: ";
                cin >> _choice;

                if (_choice == 3) exit(0);

            } while (_choice != 1 && _choice != 2);

            if (_choice == 1) goto remove_cart;
            else goto menuCustom_start;
            break;
        }

        case 4: 
        {
        edit_cart:
            cout << "\n\n--------------------------------------------- Menu ----------------------------------------------------" << endl;
            MainCart.showCart();

            cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "--------------------------------------------- Edit ----------------------------------------------------" << endl;
            cout << "Enter the product name: ";
            cin.ignore(); cin >> _name;

            try {
                if (searchByNameCart(_name) != NULL) {
                    cout << "\n------------------------------------------------------------------------------------------------------" << endl;
                    cout << "\n\t\t\tData is founded" << endl;
                    searchByNameCart(_name)->getProduct();


                    cout << "Enter the quantity of product you want to edit: ";
                    cin >> _num;

                    update(_name, _num);
                    break;
                
                    cout << "\n---------------------------------- Successfully Edit Detail -------------------------------------------" << endl << endl;
                }
                else throw false;
            } 
            catch (bool earase) {
                cout << "\n------------------------------------------------------------------------------------------------------" << endl;
                cout << "\n\t\t\tNo product in cart has this information" << endl << endl;               
            }

            do {
                cout << "\t\t\t 1. Continue editing another product " << endl;
                cout << "\t\t\t 2. Turn back Customer menu" << endl;
                cout << "\t\t\t 3. Exit program" << endl;
                cout << "\t\t\t Please Enter Your Choice: ";
                cin >> _choice;

                if (_choice == 3) exit(0);

            } while (_choice != 1 && _choice != 2);

            if (_choice == 1) goto edit_cart;
            else goto menuCustom_start;
            break;
        }
        case 5: 
        {
        get_paid:
            MainCart.showCart();
            getBill();
            try {
                do {
                    cout << "\t\t\tWhich payment method do you want?" << endl;
                    cout << "\t\t\t1. Cash" << endl;
                    cout << "\t\t\t2. DebitCard" << endl;
                    cout << "\t\t\t3. CreditCard" << endl;
                    cout << "\t\t\t4. BankTransfer" << endl;
                    cin >> _choice;
                } while (_choice < 1 || _choice > 4);

                PaymentMethod _method;
                if (_choice == 1) _method = Cash;
                else if (_choice == 2) _method = DebitCard;
                else if (_choice == 3) _method = CreditCard;
                else if (_choice == 4) _method = BankTransfer;

                cout << "Enter your password to confirm payment: " << endl;
                cin >> _password;
                if (getPassword() == _password) {
                    MainCart.getMethod(_method);
                    cout << "\n---------------------------------- Successfully Confirm Payment -------------------------------------------" << endl;
                    MainCart.shoppingCart.clear();
                    cout << "\n---------------------------------- Thank You For You Payment -------------------------------------------" << endl;
                }
                else throw false;
            } 
            catch (bool exception) {
                cout << "Confirmed password is incorrect. Please re-enter" << endl;
                goto get_paid;
            }
            break;
        }
        case 6: 
            goto menuCustom_start;
            break;

        case 7: 
        {
            cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "------------------------------------- Program Is Exit --------------------------------------------" << endl;
            exit(0);
            break;
        }

        default:
            break;  
        }

        threadAddCart.join();
        threadEraseCart.join();

        threadUpdate.join();
        threadCheckNum.join();

    }
}
