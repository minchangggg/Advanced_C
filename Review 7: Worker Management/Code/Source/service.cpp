#include "../Header/service.h"
using namespace std;

void Service::setID (int _serviceID) {
    serviceID = _serviceID;
}

int Service::getID() {
    return serviceID;
}

void Service::setName(string _name) {
    name = _name;
}

string Service::getName() {
    return name;
}

void Service::setPrice(int _price) {
    price = _price;
}

int Service::getPrice() {
    return price;
}

void Service::setData(string _name, int _price) {
    setName(_name);
    setPrice(_price);
}

//______________________________________________________________________________________________________________
list <Service> ManageService::getDish() {
    return dish;
}
list <Service> ManageService::getPool() {
    return pool;
}
list <Service> ManageService::getGym() {
    return gym;
}
list <Service> ManageService::getLaundry() {
    return laundry;
}

void ManageService::addService(string _name, int _price, list <Service> &service) {
    Service newService;
    newService.setName(_name);
    newService.setPrice(_price);
    service.push_back(newService);
}


//     case 2: // pool
//         cout << "\t\t\tEnter name for new type of pool service you want: ";
//         cin.ignore(); cin >> _name;
//         newService.setName(_name);

//         cout << "Enter price for new type of pool service you want: ";
//         cin >> _price;
//         newService.setPrice(_price);

//         pool.push_back(newService);
//         break;

//     case 3: // gym
//         cout << "\t\t\tEnter name for new type of gym service you want: ";
//         cin.ignore(); cin >> _name;
//         newService.setName(_name);

//         cout << "Enter price for new type of gym service you want: ";
//         cin >> _price;
//         newService.setPrice(_price);

//         gym.push_back(newService);
//         break;

//     case 4: // laundry
//         cout << "\t\t\tEnter name for new type of laundry service you want: ";
//         cin.ignore(); cin >> _name;
//         newService.setName(_name);

//         cout << "Enter price for new type of laundry service you want: ";
//         cin >> _price;
//         newService.setPrice(_price);

//         laundry.push_back(newService);
//         break;

//     default:
//         break;
//     }    
// } 

void ManageService::deleteService(int ID_input, list <Service> &service) {
    list<Service>::iterator it;
    for (it = service.begin(); it != service.end(); ++it) {
        if (it->getID() == ID_input) {
            cout << "\n-----------------------------------------Data is founded-----------------------------------------------" << endl << endl;
            cout << "\t\t\tID" << "\t\t\tName" << "\t\t\tPrice" << endl;
            cout << "\t\t\t" << it->getID() << "\t\t\t" << it->getName() << "\t\t\t" << it->getPrice();
            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;

            cout << "\n\t\t\tAre you sure you want to delete this item?" << endl;
            int ans = 0;
            do {
                cout << "\t\t\t1. Yes" << endl;
                cout << "2. No" << endl;
                cout << "\t\t\tPlease Enter Your Choice: " << endl;
                cin >> ans;
                if (ans == 2) return;

            } while (ans != 1);
            
            dish.erase(it);
        }
    }

    // switch (typeService) {
    // case 1: // dish
    //     for (it = dish.begin(); it != dish.end(); ++it) {
    //         if (it->getID() == ID_input) {
    //             cout << "\n-----------------------------------------Data is founded-----------------------------------------------" << endl << endl;
    //             cout << "\t\t\tID" << "\t\t\tName" << "\t\t\tPrice" << endl;
    //             cout << "\t\t\t" << it->getID() << "\t\t\t" << it->getName() << "\t\t\t" << it->getPrice();
    //             cout << "\n-------------------------------------------------------------------------------------------------------" << endl;

    //             cout << "\n\t\t\tAre you sure you want to delete this item?" << endl;
    //             int ans = 0;
    //             do {
    //                 cout << "\t\t\t1. Yes" << endl;
    //                 cout << "2. No" << endl;
    //                 cout << "\t\t\tPlease Enter Your Choice: " << endl;
    //                 cin >> ans;
    //                 if (ans == 2) return;

    //             } while (ans != 1);
                
    //             dish.erase(it);
    //         }
    //     }
    //     break;

}

void ManageService::showService(list <Service> &service) {
    int count = 0;
    cout << "\t\t\tNo" << "\t\t\tID" << "\t\t\tName" << "\t\t\tPrice" << endl;
    cout << "________________________________________________________________________________________________________" << endl;

    for (auto i : service) {
        count++;
        cout << "\t\t\t" << count << "\t\t\t" << i.getID() << "\t\t\t" << i.getName() << "\t\t\t" << i.getPrice() << endl;
        cout << "-------------------------------------------------------------------------------------------------------" << endl;
    }
} 

void ManageService::editService(int ID_input, list <Service> &service) {
    list<Service>::iterator it;
    for (it = service.begin(); it != service.end(); ++it) {
        if (it->getID() == ID_input) {
            cout << "\n-----------------------------------------Data is founded-----------------------------------------------" << endl << endl;
            cout << "\t\t\tID" << "\t\t\tName" << "\t\t\tPrice" << endl;
            cout << "\t\t\t" << it->getID() << "\t\t\t" << it->getName() << "\t\t\t" << it->getPrice();
            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;

            cout << "\n\t\t\tPlease re-enter Price of service you want to change: " << endl;
            int _price = 0; cin >> _price; 
            it->setPrice(_price);
            return;
        }
    }
} 

void ManageService::menuManageService() {
menuManageService_start:
    int _choice = 0;
    cout << "\t\t\t-------------------------------" << endl;
    cout << "\t\t\t|     SERVICE MANAGEMENT     |" << endl;
    cout << "\t\t\t-------------------------------" << endl;
    do { 
        cout << "\t\t\t 1. Food and Beverage" << endl; // 1. Đồ ăn, thức uống
        cout << "\t\t\t 2. Pool" << endl; // 2. Bể bơi
        cout << "\t\t\t 3. Gym" << endl; // 3. Gym
        cout << "\t\t\t 4. Laundry" << endl; // 4. Giặt ủi
        cout << "\t\t\t 5. Exit" << endl; // 5. Thoát
        cout << "\t\t\t............................" << endl;
        cout << "\t\t\tPlease Enter Your Choice: ";
        cin >> _choice;
    } while (_choice < 1 || _choice > 5);

    switch (_choice) {
        case 1: // 1. Đồ ăn, thức uống
        food_and_beverage_start:
            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "-------------------------------------Food and Beverage-------------------------------------------------" << endl;
            do { 
                cout << "\t\t\t 1. Add dish" << endl; // 1. Thêm món
                cout << "\t\t\t 2. Delete dish" << endl; // 2. Xóa món
                cout << "\t\t\t 3. List of dishes" << endl; // 3. Danh sách món
                cout << "\t\t\t 4. Edit dish" << endl; // 4. Sửa món
                cout << "\t\t\t 5. Turn back main menu" << endl; // 5. 	Quay lại
                cout << "\t\t\t 6. Exit program" << endl;
                cout << "\t\t\t............................" << endl;
                cout << "\t\t\tPlease Enter Your Choice: ";
                cin >> _choice;
            } while (_choice < 1 || _choice > 6);

            switch (_choice) {
            case 1:
            {
            add_menu:
                cout << "--------------------------------------------- Menu ----------------------------------------------------" << endl;
                showService(dish);
                cout << endl << endl;

                cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                cout << "----------------------------------------- Add dish ------------------------------------------------" << endl;
                cout << "\t\t\tEnter name of dish you want: ";
                string _name = ""; cin.ignore(); cin >> _name;

                cout << "Enter price of dish you want: ";
                int _price = 0; cin >> _price;
                addService(_name, _price, dish); 

                do {
                    cout << "\n\n\t\t\t 1. Continue Adding Another Dish " << endl;
                    cout << "\n\t\t\t 2. Turn back Food and Beverage menu" << endl;
                    cout << "\t\t\t 3. Exit program" << endl;
                    cout << "\t\t\tPlease Enter Your Choice: ";
                    cin >> _choice;

                    if (_choice == 3) exit(0);

                } while (_choice != 1 && _choice != 2);

                if (_choice == 1) goto add_menu;
                else goto food_and_beverage_start;
                break;
            }

            case 2: {
            delete_menu:
                cout << "--------------------------------------------- Menu ----------------------------------------------------" << endl;
                showService(dish);
                cout << endl << endl;

                cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                cout << "----------------------------------------- Delete dish -------------------------------------------------" << endl;
                cout << "\nEnter ID of Dish you want to delete: ";
                int ID_input = 0; cin >> ID_input;

                deleteService(ID_input, dish);

                do {
                    cout << "\n\n\t\t\t 1. Continue Deleting Another Dish " << endl;
                    cout << "\n\t\t\t 2. Turn back manager menu" << endl;
                    cout << "\t\t\t 3. Exit program" << endl;
                    cout << "\t\t\tPlease Enter Your Choice: ";
                    cin >> _choice;

                    if (_choice == 3) exit(0);

                } while (_choice != 1 && _choice != 2);

                if (_choice == 1) goto delete_menu;
                else goto food_and_beverage_start;
                break;
            }

            case 3: {
                cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                cout << "--------------------------------------------- Menu ----------------------------------------------------" << endl;
                showService(dish);
                
                do {
                    cout << "\n\t\t\t 1. Turn back manager menu" << endl;
                    cout << "\t\t\t 2. Exit program" << endl;
                    cout << "\t\t\tPlease Enter Your Choice: ";
                    cin >> _choice;   
                    
                    if (_choice == 3) exit(0);

                } while (_choice != 1);

                goto food_and_beverage_start;
                break;
            }

            case 4: {
            edit_menu:
                cout << "--------------------------------------------- Menu ----------------------------------------------------" << endl;
                showService(dish);
                cout << endl << endl;

                cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                cout << "------------------------------------------ Edit dish --------------------------------------------------" << endl;
                cout << "\nEnter ID of Dish you want to edit: ";
                int ID_input = 0; cin >> ID_input;

                do {
                    cout << "1, Edit Name" << endl;
                    cout << "2, Edit ID" << endl;
                    cout << "3, Edit Price" << endl;
                    cout << "Please Enter Your Choice: ";
                    cin >> _choice;
                } while (_choice < 1 && _choice >3);

                editService(ID_input, dish);

                do {
                    cout << "\n\n\t\t\t 1. Continue Editing Another Dish " << endl;
                    cout << "\n\t\t\t 2. Turn back manager menu" << endl;
                    cout << "\t\t\t 3. Exit program" << endl;
                    cout << "\t\t\tPlease Enter Your Choice: ";
                    cin >> _choice;

                    if (_choice == 3) exit(0);

                } while (_choice != 1 && _choice != 2);

                if (_choice == 1) goto edit_menu;
                else goto food_and_beverage_start;
                break;
            }
            
            case 5: 
                cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                cout << "------------------------------------- Program Is Exit --------------------------------------------" << endl;
                exit(0);
                break;

            default:
                break;  
            }

            break;

        case 2: // 2. Bể bơi
        pool_start:
            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "------------------------------------------Pool---------------------------------------------------------" << endl;
            do { 
                cout << "\t\t\t 1. Add type of pool service" << endl; // 1. Thêm món
                cout << "\t\t\t 2. Delete type of pool service" << endl; // 2. Xóa món
                cout << "\t\t\t 3. Types of pool service" << endl; // 3. Danh sách món
                cout << "\t\t\t 4. Edit type of pool service" << endl; // 4. Sửa món
                cout << "\t\t\t 5. Turn back main menu" << endl; // 5. 	Quay lại
                cout << "\t\t\t 6. Exit program" << endl;
                cout << "\t\t\t............................" << endl;
                cout << "\t\t\tPlease Enter Your Choice: ";
                cin >> _choice;
            } while (_choice < 1 || _choice > 6);

            break;

        case 3: // 3. Gym
        gym_start:
            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
            cout <<  "------------------------------------------Gym----------------------------------------------------------" << endl;  
            do { 
                cout << "\t\t\t 1. Add type of gym service" << endl; // 1. Thêm món
                cout << "\t\t\t 2. Delete type of gym service" << endl; // 2. Xóa món
                cout << "\t\t\t 3. Types of gym service" << endl; // 3. Danh sách món
                cout << "\t\t\t 4. Edit type of gym service" << endl; // 4. Sửa món
                cout << "\t\t\t 5. Turn back main menu" << endl; // 5. 	Quay lại
                cout << "\t\t\t 6. Exit program" << endl;
                cout << "\t\t\t............................" << endl;
                cout << "\t\t\tPlease Enter Your Choice: ";
                cin >> _choice;
            } while (_choice < 1 || _choice > 6);

            break;
        
        case 4: // 4. Giặt ủi
        laundry_start:
            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "----------------------------------------Laundry--------------------------------------------------------" << endl;            
            do { 
                cout << "\t\t\t 1. Add type of laundry service" << endl; // 1. Thêm món
                cout << "\t\t\t 2. Delete type of laundry service" << endl; // 2. Xóa món
                cout << "\t\t\t 3. Types of laundry service" << endl; // 3. Danh sách món
                cout << "\t\t\t 4. Edit type of laundry service" << endl; // 4. Sửa món
                cout << "\t\t\t 5. Turn back main menu" << endl; // 5. 	Quay lại
                cout << "\t\t\t 6. Exit program" << endl;
                cout << "\t\t\t............................" << endl;
                cout << "\t\t\tPlease Enter Your Choice: ";
                cin >> _choice;
            } while (_choice < 1 || _choice > 6);

            break;

        default:
            break;
    }    
}
