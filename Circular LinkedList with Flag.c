#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int flag;
    struct Node* next;
};

int main() {
    int values[] = {10, 20, 30, 40, 50};
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = values[0];
    head->flag = 1;
    head->next = head;

    struct Node* last = head;
    for (int i = 1; i < 6; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = values[i];
        newNode->flag = 0;
        newNode->next = head;
        last->next = newNode;
        last = newNode;
    }

    printf("Circular Linked List:\n\n");
    struct Node* temp = head;
    while (temp->next != head) {
        printf("[f=%d, %d] ", temp->flag, temp->data);
        temp = temp->next;
    }

   // struct Node* toDelete = head;
    head = head->next;
    last->next = head;
    head->flag = 1; 

    printf("\n\nAfter Deleting First Element:\n\n");
    temp = head;
    while (temp->next != head) {
        printf("[f=%d, %d] ", temp->flag, temp->data);
        temp = temp->next;
    }
    
printf("\n");
    return 0;
}
