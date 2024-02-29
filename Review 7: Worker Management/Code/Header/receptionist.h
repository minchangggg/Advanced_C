#ifndef _RECEPTIONIST_H
#define _RECEPTIONIST_H

#include "manager.h"

using namespace std;

class Receptionist  {
private:
    int accountt;
    int passwordd;

public:
    Receptionist() {
        this->accountt = 0;
        this->passwordd = 0;
    }

    void setAccountt(int _accountt);
    void setPasswordd(int _passwordd);
        
    int getAccountt();
    int getPasswordd();

    void checkShift(Database database); 

    void makeCheckIn(Database &database);
    void makeCheckOut(Database &database); 

    void showRoom(Database database);    

    void menuReceptionist (Database &database); 
};

#endif
