#ifndef _TABLE_H
#define _TABLE_H

#include <list>
#include "dish.h"

using namespace std;

typedef enum {
    Booked,
    Free
} Status;

class Table {
private:
    int tableID;
    Status status;
    list <Dish> menu;
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

    void setStatus(Status _status); // if (payBill()) -> status = Free;
    Status getStatus();  

    void setTableID(int _tableID);
    int getTableID();

    // 1. gọi món
    void orderDish(); 
    
    // 2. hủy món 
    void cancelDish(int ID_input); 

    // 3. đổi số lượng món đã đặt
    void changeNum(int ID_input); 

    // 4. danh sách món đã đặt 
    void getOrderList (); 

    // 5. tính bill
    int getBill(); 
    bool payBill();

};

#endif
