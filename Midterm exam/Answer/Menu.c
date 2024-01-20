/*
* File: Menu.
* Author: Ton Nu Minh Trang
* Date: 15/01/2024
* Description: This file contains all the functions/methods to building management
*/

#include "Menu.h"

void assignString(char* token, char root[]) {
    for (int i = 0; i < strlen(token); ++i) {
        root[i] = token[i];
    }
}

void readData(const char* filename, MemberNode* list) {
    char row[1000];

    FILE* file;
    file = fopen(filename, "r");
    bool isDataInfo = false;
    char *token;

    while (!feof(file)) {
        fgets(row, 1000, file);

        if (!isDataInfo) {
            isDataInfo = true;
            continue;
        }

        // printf("Row: %s", row);

        token = strtok(row, ",");
        Member currMember;
        int cnt = 0;

        while(token != NULL) {
            ++cnt;
            switch (cnt) {
                case 1:
                    assignString(token, currMember.uid);
                    break;

                case 2:
                    assignString(token, currMember.roomNumber);
                    break;

                case 3:
                    assignString(token, currMember.name);
                    break;

                case 4:
                    assignString(token, currMember.licensePlate);
                    break;
            }
            // printf("Token: %s\n", token);
            token = strtok(NULL, ",");
        }

        createMember(list, currMember);
    }

    fclose(file);
}

void writeData(const char* filename, MemberNode* list) { 
    FILE* file;
    file = fopen(filename, "w");

    MemberNode *currNode = list;
    printf("uID,roomNumber,name,licensePlates\n");
    while (currNode != NULL) {
        printf("%s,%s,%s,%s\n", currNode->data.uid, currNode->data.roomNumber, currNode->data.name, currNode->data.licensePlate);
        currNode = currNode->next;
    }

    fclose(file);
}

void Menu(const char* filename, MemberNode* list, Member member, char* searchValue, char* uid) {
    int choice_input;
    readData(filename, list);
    printf ("======Danh Sach Chuc Nang=========\n");
    printf("1. Thêm 1 dân cư mới .\n");
    printf("2. Số lượng dân cư .\n");
    printf("3. In ra toàn bộ thông tin dân cư .\n");
    printf("4. Tìm kiếm thông tin dân cư .\n");
    printf("5. Sửa thong tin dân cư\n");
    printf("6. Xóa dân cư khỏi danh sach\n");
    printf("0. Thoat chuong trinh\n");
    while (1) {
        printf("Nhap chuc nang ban  chon : ");
        scanf("%d", &choice_input);

        switch (choice_input) {
        case 1:
            printf("Moi Ban nhap thong tin 1 sinh vien : \n");
            addMember(list);
        case 2:
            printf("Số lượng dân cư : %d \n", calcPopulation(list));
        case 3:
            printf("Danh Sach thông tin dân cư : \n");
            printList(list);
        case 4:
            printf("Tìm kiếm thông tin dân cư : \n");
            searchMember(list);
        case 5:
            printf("Thông tin dân cư cần chỉnh sửa : \n");
            editMember(list);
        case 6:
            printf("Nhập thông tin dân cư xóa khỏi danh sach : \n");
            deleteMember(list);
        default:
            break;
        }
    }

    writeData(filename, list);
}
