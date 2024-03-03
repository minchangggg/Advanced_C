/*
* File: table.h
* Author: Ton Nu Minh Trang
* Date: 10/02/2024
* Description: This file is a table header file that program is used for storing table's information
*/

#ifndef _TABLE_H
#define _TABLE_H

#include <list>
#include "dish.h"

using namespace std;

typedef enum {
    Booked,
    Free
} Status;

/*
*Class: Table
*Description: This class contains basic properties and methods of a Table object
*/
class Table {
private:
    int tableID;
    Status status;
    list <Order> orderList;
    int totalBill;

public:
    Table() {
        static int _tableID = 1;
        this->tableID = _tableID;
        _tableID++;

        status = Free;
        this->totalBill = 0;
    }

    void resetTable ();

    void setStatus(Status _status); 
    Status getStatus();  

    void setTableID(int _tableID);
    int getTableID();

    void orderDish(int ID_input, list <Dish> menu); 
    
    void cancelDish(int ID_input); 

    void changeNum(int ID_input); 

    void getOrderList (int ID_input); 

    void getBill(int ID_input);
};

#endif
