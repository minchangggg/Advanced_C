#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int value;
    struct node* next;
} node;


node* createNode(int value) {
    node* ptr = (node*)malloc(sizeof(node));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}

void push_back(node** array, int value) {
    node* temp;
    temp = createNode(value); 
    if (*array == NULL) *array = temp; // if array doesn't have any node yet

    else { // if array has some node
        node* p = *array; // use p instead of array because we are using pointer, use array will change the structure of linkedlist
        while (p->next != NULL) // which mean the current node is not the last node
        {
            p = p->next;    // check next node until it a last node
        }
        p->next = temp;     // change it next member point to address of new node have just create
    }
}

void push_front(node** array, int value) {
    node* newNode = createMemberNode(value);
    newNode->next = (*array); // với *head là địa chỉ của head trong dslk
    (*array) = newNode; // cập nhật node head
}

void pop_back(node** array) {
    node* p, * temp;
    p = *array;
    int i = 0; // to 

    while (p->next->next != NULL)     // free the last node in the list
    {
        p = p->next;
        i++;
    }
    temp = p->next;
    p->next = NULL;
    free(temp);
}

int get(node* array, int pos) {
    int i = 0;
 
    while (array->next != NULL && pos != i) {
        array = array->next;
        i++;
    }

    if (pos != i) {
        printf("Error: List has less element\n");
        return 0;
    }

    int value = array->value;
    return value;
}

void push_front(node **array, int value) {
   node* temp = createNode(value);

   temp->next = *array;
   *array = temp;
}

void pop_front(node **array) {
   if (*array == NULL) return;
   node *temp = *array;
   *array = (*array)->next;
   free(temp);
}

int front(node **array) {
   return (*array)->value;
}

int back(node** array) {
   node* temp = *array;
   while (temp->next != NULL) temp = temp->next;
   return temp->value;
}

void insert(node** array, int value, int pos) {
   if (pos == 0) push_front(array, value);

   node* currNode = *array;
   node* newNode = createNode(value);

   int cnt = 0;
   while (cnt < pos - 1) {
      currNode = currNode->next;
      ++cnt;
   }

   if (cnt < pos - 1) {
      printf("Linked list has less elements than pos\n");
      return;
   }

   newNode->next = currNode->next;
   currNode->next = newNode;
}

void delete(node** array, int pos) {
   node* currNode = *array;
   if (pos == 0) pop_front(array);

   int cnt = 0;
   while(cnt < pos - 1) {
      currNode = currNode->next;
      ++cnt;
   }

   if (cnt < pos - 1) {
      printf("Linked list has less elements than pos\n");
      return;
   }

   node* temp = currNode->next;
   currNode->next = currNode->next->next;
   free(temp);
}

int size(node** array) {
   node* curr = *array;
   int cnt = 0;

   while (curr != NULL) {
      curr = curr->next;
      ++cnt;
   }

   return cnt;
}

bool empty(node **array) {
   return (*array == NULL);
}

