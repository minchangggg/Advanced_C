#include "../Header/table.h"
using namespace std;

void Table::resetTable () {
    setStatus(Free);
    orderList.clear();
}

void Table::setTableID(int _tableID) {
    tableID = _tableID;
}

int Table::getTableID() {
    return tableID;
}

void Table::setStatus(Status _status) {
    status = _status;
}

Status Table::getStatus() {
    return status;
}

void Table::orderDish(int ID_input, list <Dish> menu) {
    Order newOrder;

    cout << "Enter ID of dish you want: ";
    int _ID; cin >> _ID;

    list<Dish>::iterator it;
    for (it = menu.begin(); it != menu.end(); ++it) {
        if (it->getID() == _ID) {
            newOrder.dish.setID(it->getID());
            newOrder.dish.setName(it->getName());
            newOrder.dish.setPrice(it->getPrice());
            break;
        }
    }
    
    cout << "Enter quantity of dish you want: ";
    int _num; cin >> _num;
    newOrder.num = _num;  

    orderList.push_back(newOrder);
} 

void Table::cancelDish(int ID_input) {
    list<Order>::iterator it;
    for (it = orderList.begin(); it != orderList.end(); ++it) {
        if (it->dish.getID() == ID_input) {
            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t\tData is founded " << endl << endl;
            cout << "ID" << "\t\t\tName" << "\t\t\tPrice" << "\t\t\tQuantity" << endl;
            cout << it->dish.getID() << "\t\t\t" << it->dish.getName() << "\t\t\t" << it->dish.getPrice() << "\t\t\t" << it->num;
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
            
            orderList.erase(it);
            return;
        }
    }
} 

void Table::changeNum(int ID_input) {
    list<Order>::iterator it;
    for (it = orderList.begin(); it != orderList.end(); ++it) {
        if (it->dish.getID() == ID_input) {
            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t\tData is founded " << endl << endl;
            cout << "ID" << "\t\t\tName" << "\t\t\tPrice" << "\t\t\tQuantity" << endl;
            cout << it->dish.getID() << "\t\t\t" << it->dish.getName() << "\t\t\t" << it->dish.getPrice() << "\t\t\t" << it->num;
            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;

            cout << "\n\t\t\tPlease re-enter quantity of dish you want: " << endl;
            int ans = 0; cin >> ans;
            it->num = ans;
            return;
        }
    }
}

void Table::getOrderList(int ID_input) {
    int count = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\tList of your ordered dishes" << endl << endl;
    cout << "No" << "\t\tID" << "\t\tName" << "\t\tPrice" << "\t\tQuantity" << endl;
    for (auto i : orderList) {
        count++;
        cout << count << "\t\t" << i.dish.getID() << "\t\t" << i.dish.getName() << "\t\t" << i.dish.getPrice() << "\t\t" << i.num << endl;
    }
} 

void Table::getBill(int ID_input) {
    int _totalBill = 0;
    for (auto i : orderList) {
        _totalBill += i.dish.getPrice() * i.num;
    }
    
    getOrderList(ID_input);
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\tTotal: " << _totalBill << endl; // thành tiền
    cout << "\t\t\tVAT: 10%" << endl;
    cout << "\t\t\tGrand total: " << 110/100 * _totalBill << endl; // tổng tiền thanh toán
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;

    int ans = 0;
    do {
        cout << "\n\n\t\t\t1. Pay away" << endl;
        cout << "\t\t\t2. Turn back" << endl;
        cout << "\t\t\tPlease Enter Your Choice: " << endl;
        cin >> ans;
    } while (ans != 1);

    resetTable();
} 
