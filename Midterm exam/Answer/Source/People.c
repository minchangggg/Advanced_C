/*
* File: People.c
* Author: Ton Nu Minh Trang
* Date: 15/01/2024
* Description: This file contains all the functions/methods for information management 
*/

#include "People.h"

/*
* Description: Create MemberNode with the Member data which is used in linked list
* Input: member is Member data used to stored informatin member in every node
* Output: Return MemberNode pointer
*/

MemberNode* createMemberNode(Member member) {
    MemberNode* newNode = (MemberNode*)malloc(sizeof(MemberNode));
    newNode->data = member;
    newNode->next = NULL;
    return newNode;
}

/*
* Description: Calculate population in the given file. 
* Input: MemberNode* list
* Output: Return the Population
*/

int calcPopulation(MemberNode* list) { // Số lượng Member 
    int num = 0;
    MemberNode* curr = list;
    while (curr != NULL) {
        curr = curr->next;
        ++num;
    }
    return num;
}

/*
* Description: Search information of every member in the given file. 
* Input: MemberNode* list
* Output: Give detail information of every member
*/

void getMember(Member* member) {
    printf("%s là UID của RFID.\n ", member->uid);
    printf("%s là số phòng.\n ", member->roomNumber);
    printf("%s là tên của cư dân. \n ", member->name);
    printf("%s là biển số xe. \n ", member->licensePlate);
}

/*
* Description: Show the information of list's members stored in the given file.
* Input: MemberNode* list
* Output: information of members
*/

void printList(MemberNode* list) {
    MemberNode* currNode = list;
    int i = 0;
    int num = calcPopulation(list);

    //start from the beginning
    printf("\t\tDANH SÁCH TRÊN GỒM %d DÂN CƯ BAO GỒM:\n", num);
    while (currNode != NULL) {
        i++; printf("[%i]\n", i); 
        getMember(&currNode->data);
        printf("______________________________________________________________________________\n");
        currNode = currNode->next;
    }
}

/*
* Description: Enter the information of new member.
* Input: MemberNode* list
* Output: None
*/

Member* input(Member* member) {
    printf("Nhập thông tin cư dân\n");
    printf("Nhập UID\n"); fflush(stdin); scanf("%s", member->uid);
    printf("Nhập roomNumber\n"); fflush(stdin); scanf("%s", member->roomNumber);
    printf("Nhập name\n"); fflush(stdin); scanf("%s", member->name);
    printf("Nhập licensePlate\n"); fflush(stdin); scanf("%s", member->licensePlate);
    return member;
}

void createMember(MemberNode** list, Member member) {
    MemberNode* newNode = createMemberNode(member);
    newNode->next = (*list);
    (*list) = newNode;
}

void addMember(MemberNode** list) { // Thêm Member mới 
    Member member;
    MemberNode* newNode = createMemberNode(member);
    input(&newNode->data);
    newNode->next = (*list); // với list là địa chỉ node trong dslk
    (*list) = newNode; // cập nhật node head
}

/*
* Description: Delete member with the given UID.
* Input: MemberNode* list
* Output: None
*/

void deleteMember(MemberNode* list) { // Xóa Member
    MemberNode* currNode = list;
    int uid = 0;
    printf("Nhập id"); fflush(stdin); scanf("%d", &uid);
      
    int cnt = 0;
    while ((currNode != NULL) && (cnt < uid - 1)) {
        currNode = currNode->next;
        ++cnt;
    }

    if (cnt < uid - 1) {
        printf("No information\n");
        return;
    }

    MemberNode* temp = currNode->next;
    currNode->next = currNode->next->next;
    free(temp);
}

/*
* Description: Search member by UID number in the given file.
* Input:
*   - list: MemberNode pointer.
*   - uid:  The UID number.
* Output: Give member information when the given UID is found.
*/

void searchByUID(MemberNode* list, char* uid) {
    for (MemberNode* currNode = list; currNode != NULL; currNode = currNode->next) {
        if (currNode->data.uid == uid) getMember(&currNode->data);
    }
}

/*
* Description: Search member by licensePlate number in the given file.
* Input:
*   - list: MemberNode pointer.
*   - licensePlate: The licensePlate number.
* Output:
*   - Give member information when the given UID is found.
*/

void searchByLicensePlate(MemberNode* list, char* licensePlate) {
    for (MemberNode* currNode = list; currNode != NULL; currNode = currNode->next) {
        if (currNode->data.licensePlate == licensePlate) getMember(&currNode->data);
    }
}

/*
* Description: Search member by UID / licensePlate number in the given file. 
* Input: MemberNode* list
* Output: Give member information when the given UID / licensePlate number is found.
*/

void searchMember(MemberNode* list) {
    printf("Nhập phương thức muốn tìm kiếm\n");
    printf("1. Search by UID\n");
    printf("2. Search by license plate\n"); 

    char searchValue[20];
    int searchFunc; scanf("%d", &searchFunc);
    printf("Nhập id: "); fflush(stdin); scanf("%s", searchValue);

    switch (searchFunc) {
    case SearchByUID:
        searchByUID(list, searchValue);
    case SearchByLicensePlate:
        searchByLicensePlate(list, searchValue);
    }
}

/*
* Description: Edit the member information with the given UID.
* Input: MemberNode* list.
* Output: Give member information and allow to edit information when the given UID is found.
*/

void editMember(MemberNode* list) { // Chỉnh sửa thông tin member thông qua uid
    printf("Nhập UID dân cư cần chỉnh sửa: "); char num_uid[20]; scanf("%s", num_uid);
    for (MemberNode* currNode = list; currNode != NULL; currNode = currNode->next) {
        if (currNode->data.uid == num_uid) {
            printf("Dưới đây là thông tin cư dân bạn muốn chỉnh sửa.\n"); getMember(&currNode->data);
            printf("Tiến hành chỉnh sửa :\n"); input(&currNode->data);
        }
    }
}
