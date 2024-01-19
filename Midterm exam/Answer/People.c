#include "People.h"

int calcPopulation(const char* filename, MemberNode* list) { // Số lượng Member 
    int num = 0;
    while (list != NULL) {
        list = list->next;
        ++num;
    }
    return num;
}

void getMember(Member member) {
    printf("%s là UID của RFID.\n ", member.uid);
    printf("%s là số phòng.\n ", member.roomNumber);
    printf("%s là tên của cư dân. \n ", member.name);
    printf("%s là biển số xe. \n ", member.licensePlate);
}

void printList(char* filename, MemberNode* list) {
    MemberNode* currNode = list;
    int i = 0;
    int num = calcPopulation(filename, list);

    //start from the beginning
    while (currNode != NULL) {
        printf("\t\tDANH SÁCH TRÊN GỒM %d DÂN CƯ BAO GỒM:\n", num);
        printf("[%i]\n"); i++;
        getMember(currNode->data);
        printf("______________________________________________________________________________\t");
        currNode = currNode->next;
    }
}

Member input(Member member) {
    printf("Nhập thông tin cư dân/n");
    printf("Nhập UID/n"); fflush(stdin); scanf("%d", member.uid);
    printf("Nhập roomNumber/n"); fflush(stdin); scanf("%d", member.roomNumber);
    printf("Nhập name/n"); fflush(stdin); scanf("%d", member.name);
    printf("Nhập licensePlate/n"); fflush(stdin); scanf("%d", member.licensePlate);
    return member;
}

void addMember(const char* filename, MemberNode* &list, Member member ) { // Thêm Member mới 
    MemberNode* newNode = createMemberNode(member);
    input(newNode->data);
    newNode->next = list; // với list là địa chỉ node trong dslk
    list = newNode; // cập nhật node head
}

void deleteMember(const char* filename, MemberNode* list, char* uid) { // Xóa Member
    MemberNode* currNode = list;
    printf("Nhập id"); fflush(stdin); scanf("%d, *uid");
      
    int cnt = 0;
    while (cnt < *uid - 1) {
        currNode = currNode->next;
        ++cnt;
    }

    if (cnt < *uid - 1) {
        printf("Linked list has less elements than pos\n");
        return;
    }

    MemberNode* temp = currNode->next;
    currNode->next = currNode->next->next;
    free(temp);
}

void searchByUID(MemberNode* list, char* uid) {
    for (MemberNode* currNode = list; currNode != NULL; currNode = currNode->next) {
        if (currNode->data.uid == uid) getMember(currNode->data);
    }
}

void searchByLicensePlate(MemberNode* list, char* licensePlate) {
    for (MemberNode* currNode = list; currNode != NULL; currNode = currNode->next) {
        if (currNode->data.licensePlate == licensePlate) getMember(currNode->data);
}

Member searchMember(const char* filename, MemberNode* list, char* searchValue) {
    MemberNode* currNode = list;
   
    printf("Nhập phương thức muốn tìm kiếm\n");
    printf("1. Search by UID\n");
    printf("2. Search by license plate\n"); 

    int searchFunc; scanf("%d", &searchFunc);
    printf("Nhập id: "); fflush(stdin); scanf("%d", *searchValue);

    switch (searchFunc) {
    case SearchByUID:
        searchByUID(list, searchValue);

    case SearchByLicensePlate:
        searchByLicensePlate(list, searchValue);
    }
}

void editMember(const char* filename, MemberNode* list) { // Chỉnh sửa thông tin member thông qua uid
    printf("Nhập UID dân cư cần chỉnh sửa: "); char* num_uid; scanf("%d", num_uid);
    for (MemberNode* currNode = list; currNode != NULL; currNode = currNode->next) {
        if (currNode->data.uid == num_uid) {
            printf("Dưới đây là thông tin cư dân bạn muốn chỉnh sửa.\n"); getMember(currNode->data);
            printf("Tiến hành chỉnh sửa :\n"); input(currNode->data);
        }
    }
}
