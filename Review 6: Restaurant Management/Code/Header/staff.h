#ifndef _STAFF_H
#define _STAFF_H

#include <vector>
#include "table.h"

using namespace std;

class Staff {
    public:
        vector<Table> tableList;
    
        Staff() {}
    
        void getNumTable(int _numTable);

        void displayTable(); // hiển thị tất cả table đc set up 
        bool isFull (); // kiểm tra có full bàn không 

        void chooseTable (int _tableID); // hiện ra những bàn còn trống, sẽ đc lựa id bàn
        void getTableInfo (int _tableID, int type, list <Dish> menu);
};

#endif
