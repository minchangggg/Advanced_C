#ifndef _STAFF_H
#define _STAFF_H

#include <vector>
#include "table.h"

using namespace std;

class Staff {
    private:
        vector<Table> tableList;
    public:
        Staff() {}
        Staff (int _numTable) {
            for (int i = 0; i < (_numTable); i++) {
                Table newTable;
                tableList.push_back(newTable);  
            }
        }
    
    void displayTable(); // hiển thị tất cả table đc set up 
    bool isFull (); // kiểm tra có full bàn không 
    void chooseTable (int _tableID); // chọn bàn nếu còn dư hơn 1 bàn 
    void menuStaff();
};

#endif
