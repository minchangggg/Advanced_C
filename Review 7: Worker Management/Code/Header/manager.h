/*
* File: manager.h
* Author: Ton Nu Minh Trang
* Date: 15/02/2024
* Description: This file is a Manager header file which helps hotel system work
*/

#ifndef _MANAGER_H
#define _MANAGER_H

#include "../Header/employee.h"
#include "../Header/room.h"
#include "../Header/service.h"

typedef enum {
    Employee_function,
    Room_function,
    Service_function,
    Back_function,
    Exit_function
} Function;

/*
* Struct: Database
* Description: This struct is used for containing data of hotel
    employee: data of employees
    room: data of rooms
    service: data of services
*/
typedef struct {
    ManageEmployee employee;
    ManageRoom room;
    ManageService service;
} Database;

/*
*Class: Manager
*Description: This class contains basic properties and methods that help manager manages hotel system
*/
class Manager {
private:
    int account;
    int password;

public:
    Manager() {
        this->account = 123456789;
        this->password = 123456789;
    }

    int getAccount();
    int getPassword();
    
    void menuManager(Database &database);
};

#endif
