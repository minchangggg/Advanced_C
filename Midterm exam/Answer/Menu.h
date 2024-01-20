/*
* File: Menu.h
* Author: Ton Nu Minh Trang
* Date: 15/01/2023
* Description: This file is a menu header file that for program management 
*/

#ifndef __MENU_H
#define __MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
#include "People.h"

void Menu(const char* filename, MemberNode* list, Member member, char* searchValue, char* uid);
void readData(const char* filename, MemberNode* list);
void writeData(const char* filename, MemberNode* list);

#endif
