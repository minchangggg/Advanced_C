#ifndef _MENU_H
#define _MENU_H

#include "Student.h"

using namespace std;

void menu(list <Student>& database);

// 1.	Them sinh vien
void insert(list <Student>& database);

// 2. Sua thong tin sinh vien
void edit_detail (list <Student>& database, list<Student>::iterator it);
void modify (list <Student>& database, short int ID_input);

// 3. Xoa sinh vien
void deletee (list <Student>& database, short int ID_input);

// 4. Tim kiem sinh vien
void search_by_id(list <Student> database, short int ID_input);
void search_by_name(list <Student> database, string name_input); 

// 5. Sap xep sinh vien
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

// 6. In ra danh sach sinh vien
void print_list(list <Student> database);

// 7. Luu vao file “database_sv.csv”
void saveCSV(list <Student> &database);

#endif
