/*
* File: Menu.h
* Author: Ton Nu Minh Trang
* Date: 15/01/2024
* Description: This file is a menu header file that program is used by building manager
*/

#ifndef __MENU_H
#define __MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
#include "People.h"

void Menu(const char* filename, MemberNode** list);
void readData(const char* filename, MemberNode** list);
void writeData(const char* filename, MemberNode** list);

#endif