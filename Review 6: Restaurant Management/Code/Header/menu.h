#ifndef _MENU_H
#define _MENU_H

#include "manager.h"
#include "staff.h"

using namespace std;

typedef enum {
    managerWork,
    staffWork
} Title;

typedef struct {
    Manager managerData;
    Staff staffaData;
} Database;

static int choice;
static int quantity;

void mainMenu (Database database);

void menuStaff (Database database);

void menuManager (Database database); 

#endif
