#ifndef _MANAGER_H
#define _MANAGER_H

#include "../Header/employee.h"
#include "../Header/room.h"
#include "../Header/service.h"

typedef enum {
    Employee_function,
    Room_function,
    Service_function
} Function;

typedef struct {
    ManageEmployee employee;
    ManageRoom room;
    ManageService service;
} Database;

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
