#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

# define SearchByUID 0
# define SearchByLicensePlate 1

typedef struct Member {
    char uid[20]; // UID của RFID
    char roomNumber[10];
    char name[50];
    char licensePlate[20]; // Biển Số Xe
} Member;

typedef struct MemberNode {
    Member data;
    struct MemberNode* next;
} MemberNode;

MemberNode* createMemberNode(Member member) {
    MemberNode* newNode = (MemberNode*)malloc(sizeof(MemberNode));
    newNode->data = member;
    newNode->next = NULL;
    return newNode;
}

int calcPopulation(const char* filename, MemberNode* list);
void getMember(Member member);
void printList(const char* filename, MemberNode* list);
Member input(Member member);
void addMember(const char* filename, MemberNode* &list, Member member);
void deleteMember(const char* filename, MemberNode* list, char* uid);

void searchByUID(MemberNode* list, char* uid);
void searchByLicensePlate(MemberNode* list, char* licensePlate);
Member searchMember(const char* filename, MemberNode* list, char* searchValue);
void editMember(const char* filename, MemberNode* list);
