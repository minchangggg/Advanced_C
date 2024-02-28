#ifndef _STAFF_H
#define _STAFF_H

#include "manager.h"

using namespace std;

class Staff {
public:
    Staff() {}

    void checkShift(); // Xem ca làm
    void editInfor(); // Sửa thông tin
    void makeCheckIn(); // Đặt phòng cho khách
    void makeCheckOut(); // Trả phòng cho khách

    void menuStaff(); 
};

#endif
