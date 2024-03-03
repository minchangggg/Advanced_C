/*
* File: manager.h
* Author: Ton Nu Minh Trang
* Date: 10/02/2024
* Description: This file is a table header file that program is used for manage restaurant
*/

#ifndef _MANAGER_H
#define _MANAGER_H

#include "table.h"
using namespace std;

/*
* Class: Manager
* Description: This class contains basic properties and methods of a Manager object
*/
class Manager {
private:
    list <Dish> menu;
    int numTable;

public:
    Manager() {
        this->numTable = 0;
    }

    list <Dish> getMenu();
 
    void setNumTable (int _numTable);
    int setNumTable ();

    void addDish(); 

    void editDish(int ID_input); 

    void deleteDish(int ID_input); 

    void showMenu(); 
};

#endif
