#include "../Header/manager.h"
using namespace std;

list <Dish> Manager::getMenu() {
    return menu;
}

void Manager::setNumTable (int _numTable) {
    numTable = _numTable;
}

int Manager::setNumTable () {
    return numTable;
}

void Manager::addDish() {
    Dish newDish;

    cout << "Enter name of dish you want: ";
    string _name; 
    cin.ignore(); cin >> _name;
    newDish.setName(_name);

    cout << "Enter price of dish you want: ";
    int _price; cin >> _price;
    newDish.setPrice(_price);

    menu.push_back(newDish);
} 

void Manager::editDish(int ID_input) {
    for (auto &i : menu) {
        if (i.getID() == ID_input) {
            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t\tData is founded " << endl << endl;
            cout << "ID" << "\t\t\tName" << "\t\t\tPrice" << endl;
            cout << i.getID() << "\t\t\t" << i.getName() << "\t\t\t" << i.getPrice();
            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;

            cout << "\n\t\t\tPlease re-enter Price of dish you want to change: " << endl;
            int _price = 0; cin >> _price; 
            i.setPrice(_price);
            return;
        }
    }
} 

void Manager::deleteDish(int ID_input) {
    list<Dish>::iterator it;
    for (it = menu.begin(); it != menu.end(); ++it) {
        if (it->getID() == ID_input) {
            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t\tData is founded " << endl << endl;
            cout << "ID" << "\t\t\tName" << "\t\t\tPrice" << endl;
            cout << it->getID() << "\t\t\t" << it->getName() << "\t\t\t" << it->getPrice();
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
            
            menu.erase(it);
            return;
        }
    }
}

void Manager::showMenu() {
    int count = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\tList of your ordered dishes" << endl << endl;
    cout << "No" << "\t\tID" << "\t\tName" << "\t\tPrice" << endl;
    for (auto i : menu) {
        count++;
        cout << count << "\t\t" << i.getID() << "\t\t" << i.getName() << "\t\t" << i.getPrice() << endl;
    }
} 
