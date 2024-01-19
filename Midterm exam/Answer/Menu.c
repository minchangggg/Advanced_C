#include "Menu.h"

void readData(const char* filename, MemberNode* list) {
    int MAXCHAR = 1000;

    FILE* file;
    file = fopen(filename, "r");
    bool isDataInfo = false;
    char *token;

    while (feof(file) != true) {
        fgets(row, MAXCHAR, file);

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
                    currMember.uid = token;
                    break;

                case 2:
                    currMember.roomNumber = token;
                    break;

                case 3:
                    currMember.name = token;
                    break;

                case 4:
                    currMember.licensePlate = token;
                    break;
            }
            // printf("Token: %s\n", token);
            token = strtok(NULL, ",");
        }

        list.addMember(currMember);
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
            writeData(filename, list);
            addMember(filename, list, member);
        case 2:
            readData(filename, list);
            printf("Số lượng dân cư : %d \n", calcPopulation);
        case 3:
            printf("Danh Sach thông tin dân cư : \n");
            readData(filename, list);
            printList(filename, list);
        case 4:
            printf("Tìm kiếm thông tin dân cư : \n");
            readData(filename, list);
            searchMember(filename, list, searchValue, member);
        case 5:
            printf("Thông tin dân cư cần chỉnh sửa : \n");
            writeData(filename, list);
            editMember(filename, list, searchValue);
        case 6:
            printf("Nhập thông tin dân cư xóa khỏi danh sach : \n");
            writeData(filename, list);
            deleteMember(filename, list, uid);
        default:
            break;
        }
    }
}
