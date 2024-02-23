#include "staff.h"
using namespace std;

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

void Staff::chooseTable() {}

void Staff::menuStaff() {}
