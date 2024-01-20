/*
* File: Menu.h
* Author: Ton Nu Minh Trang
* Date: 15/01/2024
* Description: This is file to manage building
*/

#include "Menu.h"

MemberNode* list = NULL;

int main() {
	Menu("10000_Members.csv", &list);
	// system("pause");
	return 0;
}
