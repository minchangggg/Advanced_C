#ifndef _MENU_H
#define _MENU_H

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

static int _choice;

void mainMenu(Database &database);

void menuManager(Database &database);

void menuStaff(Database &database);

#endif
