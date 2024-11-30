#include <stdio.h>
#include <stdlib.h>

int main() {
    struct node {
        int data;
        struct node *next;
    };

    struct node *head, *first, *temp = NULL;
    int choice = 1;

    first = NULL;

    while (choice) {
        head = (struct node*)malloc(sizeof(struct node));

        printf("Enter element to insert into the linked list: ");
        scanf("%d", &head->data);
        head->next = NULL;

        if (first != NULL) {
            temp->next = head;
            temp = head;
        } else {
            first = temp = head;
        }

        printf("Do you want to continue (Type 1 to continue or 0 to exit)? : ");
        scanf("%d", &choice);
    }

    temp = first;
    printf("\nThe linked list elements are: \n");
    while (temp != NULL) {
        printf("[%d] -> ",temp->data);
        temp = temp->next;
    }
    printf("[NULL]\n");

    return 0;
}
