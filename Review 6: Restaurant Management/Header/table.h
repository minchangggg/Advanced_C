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
    list <Order> dish_order;
    int totalBill;

public:
    Table() {
        static int _tableID = 1;
        this->tableID = _tableID;
        _tableID++;

        status = Free;
        this->totalBill = 0;
    }

    void setTableID(int _ID);
    int getTableID();

    void setStatus(Status _status);
    Status getStatus(); 

    void orderDish(); // 1. gọi món
    void cancelDish(); // 2. hủy món
    void changeOrder(); // 3. đổi món
    list <Order> getOrderList (); // 4. danh sách món đã đặt 
    void getBill(); // 5. tính bill 
};

#endif
