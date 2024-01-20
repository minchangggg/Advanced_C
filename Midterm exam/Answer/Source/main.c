/*
* File: Menu.h
* Author: Ton Nu Minh Trang
* Date: 15/01/2024
* Description: This is file to manage building
*/

#include "Menu.h"

Member member;
MemberNode* list = NULL;
char* searchValue; char* uid;

int main() {
	Menu( "10000_Members.csv", list, member, searchValue, uid);
	// system("pause");
	return 0;
}
