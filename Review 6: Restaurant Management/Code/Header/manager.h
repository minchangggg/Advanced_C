#ifndef _MANAGER_H
#define _MANAGER_H

#include "table.h"
using namespace std;

class Manager {
private:
    list <Dish> menu;
    int numTable; // số lượng bàn set up
public:
    Manager(int _numTable) {
        this-> numTable = _numTable;
    }

    // 1. Set up số bàn    
    void setNumTable (int _numTable);
    int setNumTable ();

    // 2. Thêm món
    void addDish(Dish dish); 

    // 3. Sửa món
    void editDish(Dish dish); 

    // 4. Xóa món
    void deleteDish(Dish dish); 

    // 5. Danh sách món
    void showMenu(); 
};

#endif
