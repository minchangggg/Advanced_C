/*
* File: receptionist.h
* Author: Ton Nu Minh Trang
* Date: 15/02/2024
* Description: This file is a Receptionist header file which helps hotel system work
*/

#ifndef _RECEPTIONIST_H
#define _RECEPTIONIST_H

#include "manager.h"

using namespace std;

/*
*Class: Receptionist
*Description: This class contains basic properties and methods that help receptionist manages hotel system
*/
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
