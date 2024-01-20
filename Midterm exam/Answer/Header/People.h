/*
* File: People.h
* Author: Ton Nu Minh Trang
* Date: 15/01/2024
* Description: This file is a people header file that program is used to store information
*/

#ifndef __PEOPLE_H
#define __PEOPLE_H

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

# define SearchByUID 0
# define SearchByLicensePlate 1

/*
*Struct: Member
*Description: This struct contains basic information of a Member object including UID, roomNumber, name, licensePlate 
*/

typedef struct Member {
    char uid[20]; // UID của RFID
    char roomNumber[10];
    char name[50];
    char licensePlate[20]; // Biển Số Xe
} Member;

/*
*Struct: MemberNode 
*Description: This struct is the basic information of node which contains information of a Member object in linked list 
*/

typedef struct MemberNode {
    Member data;
    struct MemberNode* next;
} MemberNode;

MemberNode* createMemberNode(Member member);

int calcPopulation(MemberNode* list);
void getMember(Member* member);
void printList(MemberNode* list);
Member* input(Member* member);
void createMember(MemberNode** list, Member member);
void addMember(MemberNode** list);
void deleteMember(MemberNode* list);

void searchByUID(MemberNode* list, char* uid);
void searchByLicensePlate(MemberNode* list, char* licensePlate);
void searchMember(MemberNode* list);
void editMember(MemberNode* list);

#endif
