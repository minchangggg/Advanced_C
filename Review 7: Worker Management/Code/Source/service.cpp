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

            cout << "\n\t\t\tPlease re-enter Price of services you want to change: " << endl;
            int _price = 0; cin >> _price; 
            it->setPrice(_price);
            return;
        }
    }
} 

void ManageService::menuManageService() {
    int _choice = 0;
    menuManageService_start:
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t|     SERVICE MANAGEMENT     |" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        do { 
            cout << "\t\t\t 1. Food and Beverage" << endl; // 1. Đồ ăn, thức uống
            cout << "\t\t\t 2. Pool" << endl; // 2. Bể bơi
            cout << "\t\t\t 3. Gym" << endl; // 3. Gym
            cout << "\t\t\t 4. Laundry" << endl; // 4. Giặt ủi
            cout << "\t\t\t 5. Turn Back Staff Menu" << endl; // 5. Thoát
            cout << "\t\t\t 6. Exit" << endl; // 6. Thoát
            cout << "\t\t\t............................" << endl;
            cout << "\t\t\tPlease Enter Your Choice: ";
            cin >> _choice;
        } while (_choice < 1 || _choice > 5);

        switch (_choice) {
            case 1: // 1. Đồ ăn, thức uống
            {
            food_and_beverage_start:
                cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
                cout << "-------------------------------------Food and Beverage-------------------------------------------------" << endl;
                do { 
                    cout << "\t\t\t 1. Add Dish" << endl; // 1. Thêm món
                    cout << "\t\t\t 2. Delete Dish" << endl; // 2. Xóa món
                    cout << "\t\t\t 3. List Of Dishes" << endl; // 3. Danh sách món
                    cout << "\t\t\t 4. Edit Dish" << endl; // 4. Sửa món
                    cout << "\t\t\t 5. Turn Back Service Menu" << endl; // 5. Quay lại
                    cout << "\t\t\t 6. Exit Program" << endl; // 6. Thoát ctr
                    cout << "\t\t\t............................" << endl;
                    cout << "\t\t\tPlease Enter Your Choice: ";
                    cin >> _choice;
                } while (_choice < 1 || _choice > 6);

                switch (_choice) {
                case 1:
                {
                add_dish:
                    cout << "\n\n--------------------------------------------- Menu ----------------------------------------------------" << endl;
                    showService(dish);

                    cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
                    cout << "------------------------------------------- Add -------------------------------------------------------" << endl;
                    cout << "\t\t\tEnter name of Dish you want: ";
                    string _name = ""; cin.ignore(); cin >> _name;

                    cout << "\t\t\tEnter price of dish you want: ";
                    int _price = 0; cin >> _price;
                    addService(_name, _price, dish); 
                    cout << "\n---------------------------------- Successfully Add Detail --------------------------------------------" << endl;

                    do {
                        cout << "\n\n\t\t\t 1. Continue adding another Dish " << endl;
                        cout << "\n\t\t\t 2. Turn back Food and Beverage menu" << endl;
                        cout << "\t\t\t 3. Exit program" << endl;
                        cout << "\t\t\tPlease Enter Your Choice: ";
                        cin >> _choice;

                        if (_choice == 3) exit(0);

                    } while (_choice != 1 && _choice != 2);

                    if (_choice == 1) goto add_dish;
                    else goto food_and_beverage_start;
                    break;
                }

                case 2: {
                delete_dish:
                    cout << "\n\n--------------------------------------------- Menu ----------------------------------------------------" << endl;
                    showService(dish);

                    cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
                    cout << "------------------------------------------- Delete ----------------------------------------------------" << endl;
                    cout << "Enter ID of Dish you want to delete: ";
                    int ID_input = 0; cin >> ID_input;

                    deleteService(ID_input, dish);
                    cout << "\n---------------------------------- Successfully Delete Detail -----------------------------------------" << endl;

                    do {
                        cout << "\n\n\t\t\t 1. Continue deleting another Dish " << endl;
                        cout << "\n\t\t\t 2. Turn back Food and Beverage menu" << endl;
                        cout << "\t\t\t 3. Exit program" << endl;
                        cout << "\t\t\tPlease Enter Your Choice: ";
                        cin >> _choice;

                        if (_choice == 3) exit(0);

                    } while (_choice != 1 && _choice != 2);

                    if (_choice == 1) goto delete_dish;
                    else goto food_and_beverage_start;
                    break;
                }

                case 3: {
                    cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
                    cout << "--------------------------------------------- Menu ----------------------------------------------------" << endl;
                    showService(dish);
                    
                    do {
                        cout << "\n\n\t\t\t 1. Turn back Food and Beverage menu" << endl;
                        cout << "\t\t\t 2. Exit program" << endl;
                        cout << "\t\t\tPlease Enter Your Choice: ";
                        cin >> _choice;   
                        
                        if (_choice == 3) exit(0);

                    } while (_choice != 1);

                    goto food_and_beverage_start;
                    break;
                }

                case 4: {
                edit_dish:
                    cout << "\n\n--------------------------------------------- Menu ----------------------------------------------------" << endl;
                    showService(dish);

                    cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
                    cout << "--------------------------------------------- Edit ----------------------------------------------------" << endl;
                    cout << "Enter ID of Dish you want to edit: ";
                    int ID_input = 0; cin >> ID_input;

                    editService(ID_input, dish);
                    cout << "\n---------------------------------- Successfully Edit Detail -------------------------------------------" << endl;

                    do {
                        cout << "\n\n\t\t\t 1. Continue editing another Dish " << endl;
                        cout << "\n\t\t\t 2. Turn back Food and Beverage menu" << endl;
                        cout << "\t\t\t 3. Exit program" << endl;
                        cout << "\t\t\tPlease Enter Your Choice: ";
                        cin >> _choice;

                        if (_choice == 3) exit(0);

                    } while (_choice != 1 && _choice != 2);

                    if (_choice == 1) goto edit_dish;
                    else goto food_and_beverage_start;
                    break;
                }

                case 5: 
                    goto menuManageService_start;

                case 6: {
                    cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
                    cout << "------------------------------------- Program Is Exit --------------------------------------------" << endl;
                    exit(0);
                    break;
                }

                default:
                    break;  
                }

                break;
            }

            case 2: // 2. Bể bơi
            {
            pool_start:
                cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
                cout << "------------------------------------------Pool---------------------------------------------------------" << endl;
                do { 
                    cout << "\t\t\t 1. Add Type Of Pool Services" << endl; // 1. Thêm 
                    cout << "\t\t\t 2. Delete Type Of Pool Services" << endl; // 2. Xóa 
                    cout << "\t\t\t 3. Types Of Pool Services" << endl; // 3. Danh sách 
                    cout << "\t\t\t 4. Edit Type Of Pool Services" << endl; // 4. Sửa 
                    cout << "\t\t\t 5. Turn Back Service Menu" << endl; // 5. 	Quay lại
                    cout << "\t\t\t 6. Exit Program" << endl;
                    cout << "\t\t\t............................" << endl;
                    cout << "\t\t\tPlease Enter Your Choice: ";
                    cin >> _choice;
                } while (_choice < 1 || _choice > 6);


                switch (_choice) { 
                case 1:
                {
                add_pool:
                    cout << "\n\n--------------------------------------------- Menu ----------------------------------------------------" << endl;
                    showService(pool);

                    cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
                    cout << "------------------------------------------- Add -------------------------------------------------------" << endl;
                    cout << "\t\t\tEnter name for new type of pool services you want: ";
                    string _name = ""; cin.ignore(); cin >> _name;

                    cout << "\t\t\tEnter price for new type of pool services you want: ";
                    int _price = 0; cin >> _price;
                    addService(_name, _price, pool); 
                    cout << "\n---------------------------------- Successfully Add Detail --------------------------------------------" << endl;

                    do {
                        cout << "\n\n\t\t\t 1. Continue adding another type of Pool services " << endl;
                        cout << "\n\t\t\t 2. Turn back Pool services menu" << endl;
                        cout << "\t\t\t 3. Exit program" << endl;
                        cout << "\t\t\tPlease Enter Your Choice: ";
                        cin >> _choice;

                        if (_choice == 3) exit(0);

                    } while (_choice != 1 && _choice != 2);

                    if (_choice == 1) goto add_pool;
                    else goto pool_start;
                    break;
                }

                case 2: {
                delete_pool:
                    cout << "\n\n--------------------------------------------- Menu ----------------------------------------------------" << endl;
                    showService(pool);

                    cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
                    cout << "--------------------------------------------Delete-----------------------------------------------------" << endl;
                    cout << "Enter ID's type of pool services you want to delete: ";
                    int ID_input = 0; cin >> ID_input;

                    deleteService(ID_input, pool);
                    cout << "\n---------------------------------- Successfully Delete Detail -----------------------------------------" << endl;

                    do {
                        cout << "\n\n\t\t\t 1. Continue deleting another type of Pool services " << endl;
                        cout << "\n\t\t\t 2. Turn back Pool services menu" << endl;
                        cout << "\t\t\t 3. Exit program" << endl;
                        cout << "\t\t\tPlease Enter Your Choice: ";
                        cin >> _choice;

                        if (_choice == 3) exit(0);

                    } while (_choice != 1 && _choice != 2);

                    if (_choice == 1) goto delete_pool;
                    else goto pool_start;
                    break;
                }

                case 3: {
                    cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
                    cout << "--------------------------------------------- Menu ----------------------------------------------------" << endl;
                    showService(pool);
                    
                    do {
                        cout << "\n\n\t\t\t 1. Turn back Pool services menu" << endl;
                        cout << "\t\t\t 2. Exit program" << endl;
                        cout << "\t\t\tPlease Enter Your Choice: ";
                        cin >> _choice;   
                        
                        if (_choice == 3) exit(0);

                    } while (_choice != 1);

                    goto pool_start;
                    break;
                }

                case 4: {
                edit_pool:
                    cout << "\n\n--------------------------------------------- Menu ----------------------------------------------------" << endl;
                    showService(pool);

                    cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
                    cout << "--------------------------------------------- Edit ----------------------------------------------------" << endl;
                    cout << "Enter ID's type of Pool servicess you want to edit: ";
                    int ID_input = 0; cin >> ID_input;

                    editService(ID_input, pool);
                    cout << "\n---------------------------------- Successfully Edit Detail -------------------------------------------" << endl;

                    do {
                        cout << "\n\n\t\t\t 1. Continue editing Another Dish " << endl;
                        cout << "\n\t\t\t 2. Turn back Pool services menu" << endl;
                        cout << "\t\t\t 3. Exit program" << endl;
                        cout << "\t\t\tPlease Enter Your Choice: ";
                        cin >> _choice;

                        if (_choice == 3) exit(0);

                    } while (_choice != 1 && _choice != 2);

                    if (_choice == 1) goto edit_pool;
                    else goto pool_start;
                    break;
                }

                case 5:
                    goto menuManageService_start;

                case 6: {
                    cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
                    cout << "------------------------------------- Program Is Exit --------------------------------------------" << endl;
                    exit(0);
                    break;
                }

                default:
                    break;  
                }

                break;
            }

            case 3: // 3. Gym
            {
            gym_start:
                cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
                cout <<  "------------------------------------------Gym----------------------------------------------------------" << endl;  
                do { 
                    cout << "\t\t\t 1. Add Type Of Gym Services" << endl; // 1. Thêm 
                    cout << "\t\t\t 2. Delete Type Of Gym Services" << endl; // 2. Xóa 
                    cout << "\t\t\t 3. Types Of Gym Services" << endl; // 3. Danh sách 
                    cout << "\t\t\t 4. Edit Type Of Gym Services" << endl; // 4. Sửa 
                    cout << "\t\t\t 5. Turn Back Service Menu" << endl; // 5. 	Quay lại
                    cout << "\t\t\t 6. Exit Program" << endl;
                    cout << "\t\t\t............................" << endl;
                    cout << "\t\t\tPlease Enter Your Choice: ";
                    cin >> _choice;
                } while (_choice < 1 || _choice > 6);

                switch (_choice) { 
                case 1:
                {
                add_gym:
                    cout << "\n\n--------------------------------------------- Menu ----------------------------------------------------" << endl;
                    showService(gym);

                    cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
                    cout << "------------------------------------------- Add -------------------------------------------------------" << endl;
                    cout << "\t\t\tEnter name for new type of Gym services you want: ";
                    string _name = ""; cin.ignore(); cin >> _name;

                    cout << "\t\t\tEnter price for new type of Gym services you want: ";
                    int _price = 0; cin >> _price;
                    addService(_name, _price, gym); 
                    cout << "\n---------------------------------- Successfully Add Detail --------------------------------------------" << endl;

                    do {
                        cout << "\n\n\t\t\t 1. Continue adding another type of Gym services " << endl;
                        cout << "\n\t\t\t 2. Turn back Gym services menu" << endl;
                        cout << "\t\t\t 3. Exit program" << endl;
                        cout << "\t\t\tPlease Enter Your Choice: ";
                        cin >> _choice;

                        if (_choice == 3) exit(0);

                    } while (_choice != 1 && _choice != 2);

                    if (_choice == 1) goto add_gym;
                    else goto gym_start;
                    break;
                }

                case 2: {
                delete_gym:
                    cout << "\n\n--------------------------------------------- Menu ----------------------------------------------------" << endl;
                    showService(gym);

                    cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
                    cout << "--------------------------------------------Delete-----------------------------------------------------" << endl;
                    cout << "Enter ID's type of Gym services you want to delete: ";
                    int ID_input = 0; cin >> ID_input;

                    deleteService(ID_input, gym);
                    cout << "\n---------------------------------- Successfully Delete Detail -----------------------------------------" << endl;

                    do {
                        cout << "\n\n\t\t\t 1. Continue deleting another type of Gym services " << endl;
                        cout << "\n\t\t\t 2. Turn back Gym services menu" << endl;
                        cout << "\t\t\t 3. Exit program" << endl;
                        cout << "\t\t\tPlease Enter Your Choice: ";
                        cin >> _choice;

                        if (_choice == 3) exit(0);

                    } while (_choice != 1 && _choice != 2);

                    if (_choice == 1) goto delete_gym;
                    else goto gym_start;
                    break;
                }

                case 3: {
                    cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
                    cout << "--------------------------------------------- Menu ----------------------------------------------------" << endl;
                    showService(pool);
                    
                    do {
                        cout << "\n\n\t\t\t 1. Turn back Gym services menu" << endl;
                        cout << "\t\t\t 2. Exit program" << endl;
                        cout << "\t\t\tPlease Enter Your Choice: ";
                        cin >> _choice;   
                        
                        if (_choice == 3) exit(0);

                    } while (_choice != 1);

                    goto gym_start;
                    break;
                }

                case 4: {
                edit_gym:
                    cout << "\n\n--------------------------------------------- Menu ----------------------------------------------------" << endl;
                    showService(pool);

                    cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
                    cout << "--------------------------------------------- Edit ----------------------------------------------------" << endl;
                    cout << "Enter ID's type of Gym services you want to edit: ";
                    int ID_input = 0; cin >> ID_input;

                    editService(ID_input, gym);
                    cout << "\n---------------------------------- Successfully Edit Detail -------------------------------------------" << endl;

                    do {
                        cout << "\n\n\t\t\t 1. Continue editing another type of Gym services " << endl;
                        cout << "\n\t\t\t 2. Turn back Gym services menu" << endl;
                        cout << "\t\t\t 3. Exit program" << endl;
                        cout << "\t\t\tPlease Enter Your Choice: ";
                        cin >> _choice;

                        if (_choice == 3) exit(0);

                    } while (_choice != 1 && _choice != 2);

                    if (_choice == 1) goto edit_gym;
                    else goto gym_start;
                    break;
                }
                
                case 5:
                    goto menuManageService_start;

                case 6: {
                    cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
                    cout << "------------------------------------- Program Is Exit --------------------------------------------" << endl;
                    exit(0);
                    break;
                }

                default:
                    break;  
                }

                break;
            }

            case 4: // 4. Giặt ủi
            {
            laundry_start:
                cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
                cout << "----------------------------------------Laundry--------------------------------------------------------" << endl;            
                do { 
                    cout << "\t\t\t 1. Add Type Of Laundry Services" << endl; // 1. Thêm món
                    cout << "\t\t\t 2. Delete Type Of Laundry Services" << endl; // 2. Xóa món
                    cout << "\t\t\t 3. Types Of Laundry Services" << endl; // 3. Danh sách món
                    cout << "\t\t\t 4. Edit Type Of Laundry Services" << endl; // 4. Sửa món
                    cout << "\t\t\t 5. Turn Back Service Menu" << endl; // 5. 	Quay lại
                    cout << "\t\t\t 6. Exit program" << endl;
                    cout << "\t\t\t............................" << endl;
                    cout << "\t\t\tPlease Enter Your Choice: ";
                    cin >> _choice;
                } while (_choice < 1 || _choice > 6);

                switch (_choice) { 
                case 1:
                {
                add_laundry:
                    cout << "\n\n--------------------------------------------- Menu ----------------------------------------------------" << endl;
                    showService(laundry);

                    cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
                    cout << "------------------------------------------- Add -------------------------------------------------------" << endl;
                    cout << "\t\t\tEnter name for new type of Laundry services you want: ";
                    string _name = ""; cin.ignore(); cin >> _name;

                    cout << "\t\t\tEnter price for new type of Laundry services you want: ";
                    int _price = 0; cin >> _price;
                    addService(_name, _price, laundry);
                    cout << "\n---------------------------------- Successfully Add Detail --------------------------------------------" << endl; 

                    do {
                        cout << "\n\n\t\t\t 1. Continue adding another type of Laundry services " << endl;
                        cout << "\n\t\t\t 2. Turn back Laundry services menu" << endl;
                        cout << "\t\t\t 3. Exit program" << endl;
                        cout << "\t\t\tPlease Enter Your Choice: ";
                        cin >> _choice;

                        if (_choice == 3) exit(0);

                    } while (_choice != 1 && _choice != 2);

                    if (_choice == 1) goto add_laundry;
                    else goto laundry_start;
                    break;
                }

                case 2: {
                delete_laundry:
                    cout << "\n\n--------------------------------------------- Menu ----------------------------------------------------" << endl;
                    showService(laundry);
                    cout << endl << endl;

                    cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
                    cout << "------------------------------------------- Delete ----------------------------------------------------" << endl;
                    cout << "Enter ID's type of Laundry services you want to delete: ";
                    int ID_input = 0; cin >> ID_input;

                    deleteService(ID_input, laundry);
                    cout << "\n---------------------------------- Successfully Delete Detail -----------------------------------------" << endl;

                    do {
                        cout << "\n\n\t\t\t 1. Continue deleting another type of Laundry services " << endl;
                        cout << "\n\t\t\t 2. Turn back Laundry services menu" << endl;
                        cout << "\t\t\t 3. Exit program" << endl;
                        cout << "\t\t\tPlease Enter Your Choice: ";
                        cin >> _choice;

                        if (_choice == 3) exit(0);

                    } while (_choice != 1 && _choice != 2);

                    if (_choice == 1) goto delete_laundry;
                    else goto laundry_start;
                    break;
                }

                case 3: {
                    cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
                    cout << "--------------------------------------------- Menu ----------------------------------------------------" << endl;
                    showService(laundry);
                    
                    do {
                        cout << "\n\n\t\t\t 1. Turn back Laundry services menu" << endl;
                        cout << "\t\t\t 2. Exit program" << endl;
                        cout << "\t\t\tPlease Enter Your Choice: ";
                        cin >> _choice;   
                        
                        if (_choice == 3) exit(0);

                    } while (_choice != 1);

                    goto laundry_start;
                    break;
                }

                case 4: {
                edit_laundry:
                
                    cout << "\n\n--------------------------------------------- Menu ----------------------------------------------------" << endl;
                    showService(pool);

                    cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
                    cout << "------------------------------------------- Edit ------------------------------------------------------" << endl;
                    cout << "Enter ID's type of Laundry services you want to edit: ";
                    int ID_input = 0; cin >> ID_input;

                    editService(ID_input, laundry);
                    cout << "\n---------------------------------- Successfully Edit Detail -------------------------------------------" << endl;

                    do {
                        cout << "\n\n\t\t\t 1. Continue editing another type of Laundry services " << endl;
                        cout << "\n\t\t\t 2. Turn back Laundry services menu" << endl;
                        cout << "\t\t\t 3. Exit program" << endl;
                        cout << "\t\t\tPlease Enter Your Choice: ";
                        cin >> _choice;

                        if (_choice == 3) exit(0);

                    } while (_choice != 1 && _choice != 2);

                    if (_choice == 1) goto edit_laundry;
                    else goto laundry_start;
                    break;
                }
                
                case 5: {
                    cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
                    cout << "------------------------------------- Program Is Exit --------------------------------------------" << endl;
                    exit(0);
                    break;
                }

                default: 
                    goto menuManageService_start;  
                }

                break;
            }

            case 5: 
                break;
            
            case 6:
                cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
                cout << "------------------------------------- Program Is Exit --------------------------------------------" << endl;
                exit(0);
                break;               

            default:
                break;
            }   
}
