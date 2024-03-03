/*
* File: Menu.h
* Author: Ton Nu Minh Trang
* Date: 5/02/2024
* Description: This file is a Menu header file that program is used for managing students of school
*/

#ifndef _MENU_H
#define _MENU_H

#include "Student.h"

using namespace std;

void menu(list <Student>& database);

void insert(list <Student>& database);

void edit_detail (list <Student>& database, list<Student>::iterator it);
void modify (list <Student>& database, short int ID_input);

void deletee (list <Student>& database, short int ID_input);

void search_by_id(list <Student> database, short int ID_input);
void search_by_name(list <Student> database, string name_input); 

bool cmpName(const Student &a, const Student &b);
bool cmpMath(const Student &a, const Student &b);
bool cmpPhysic(const Student &a, const Student &b);
bool cmpChemical(const Student &a, const Student &b);
bool cmpAverScore(const Student& a, const Student &b);

void sort_name(list <Student> &database);
void sort_math_score(list <Student> &database);
void sort_physic_score(list <Student> &database);
void sort_mechical_score(list <Student> &database);
void sort_average_score(list <Student> &database);

void print_list(list <Student> database);

void saveCSV(list <Student> &database);

#endif
