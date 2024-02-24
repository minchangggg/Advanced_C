#ifndef _MANAGER_H
#define _MANAGER_H

#include "table.h"
using namespace std;

class Manager {
private:
    list <Dish> menu;
    int numTable; // số lượng bàn set up

public:
    Manager() {
        this->numTable = 0;
    }

    list <Dish> getMenu();
    
    // 1. Set up số bàn    
    void setNumTable (int _numTable);
    int setNumTable ();

    // 2. Thêm món
    void addDish(); 

    // 3. Sửa món
    void editDish(int ID_input); 

    // 4. Xóa món
    void deleteDish(int ID_input); 

    // 5. Danh sách món
    void showMenu(); 
};

#endif
