#include "../Header/staff.h"
using namespace std;

void Staff::getNumTable(int _numTable) {
    for (int i = 0; i < (_numTable); i++) {
        Table newTable;
            tableList.push_back(newTable);  
    }
}

void Staff::displayTable() {
    cout << "Table ID" << "\t\t";
    for (int i = 0; i < tableList.size(); i++) {
        cout << i+1 << "\t";
    }

    cout << "\n Status " << "\t\t";
    for (auto it : tableList) {
        if (it.getStatus() == Free) cout << "O" << "\t";
        else cout << "X" << "\t";
    }

    cout << "\n\nX means booked";
    cout << "\nO means free";
}

bool Staff::isFull() {
    for (auto it : tableList) {
        if (it.getStatus() == Free) return false;
    }
    return false;
}

void Staff::chooseTable(int _tableID) {
    for (auto &i : tableList) {
        if (i.getTableID() == _tableID) {
            i.setStatus(Booked);
        }
    }
}

void Staff::getTableInfo (int _tableID, int type, list <Dish> menu) {
    for (auto &it : tableList) {
        if (it.getTableID() == _tableID) {
            switch(type) {
                case 1: // gọi
                    it.orderDish(_tableID, menu);
                    break;
                case 2: // hủy
                    it.cancelDish(_tableID);
                    break;
                case 3: // thay đổi
                    it.changeNum(_tableID);
                    break;
                case 4: // in ra danh sách 
                    it.getOrderList(_tableID);
                    break;
                case 5:
                    it.getBill(_tableID);
                    break;
                default:
                    break;
            }
        }
    }
}
