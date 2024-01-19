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

MemberNode* createMemberNode(Member member);

int calcPopulation(MemberNode* list);
void getMember(Member &member);
void printList(MemberNode* list);
Member input(Member &member);
void addMember(MemberNode* &list, Member member);
void addMember(MemberNode* &list);
void deleteMember(MemberNode* list);

void searchByUID(MemberNode* list, char* uid);
void searchByLicensePlate(MemberNode* list, char* licensePlate);
Member searchMember(MemberNode* list);
void editMember(MemberNode* list);
