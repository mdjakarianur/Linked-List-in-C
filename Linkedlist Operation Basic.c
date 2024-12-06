#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void display(struct node* head) {
    struct node* temp = head;
    printf("\nLinkedList Elements Are:\n");
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertAtBeginning(struct node** head_first, int new_data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    
    newNode->data = new_data;
    newNode->next = *head_first;
    *head_first = newNode;
    printf("Inserted %d at the beginning.\n", new_data);
}

void insertAtEnd(struct node** head_first, int new_data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    
    newNode->data = new_data;
    newNode->next = NULL;

    struct node* temp = *head_first;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Inserted %d at the end.\n", new_data);
}

void insertAtPosition(struct node** head_first, int new_data, int position) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    
    newNode->data = new_data;

    struct node* temp = *head_first;
    for(int i = 1; i < position-1 && temp != NULL; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d.\n", new_data, position);
}

void deleteFromBeginning(struct node** head_first) {
    if(*head_first == NULL){
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct node* temp = *head_first;
    *head_first = (*head_first)->next;
    printf("Deleted %d from the beginning.\n", temp->data);
    free(temp);
}

void deleteFromEnd(struct node** head_first) {
    if(*head_first == NULL){
        printf("List is empty.\n");
        return;
    }
    if((*head_first)->next == NULL){
        printf("Deleted %d from the end.\n", (*head_first)->data);
        free(*head_first);
        *head_first = NULL;
        return;
    }

    struct node* temp = *head_first;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    printf("Deleted %d from the end.\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

void deleteAtPosition(struct node** head_first, int position) {
    if(*head_first == NULL){
        printf("List is empty.\n");
        return;
    }
    if(position < 1){
        printf("Position should be >= 1.\n");
        return;
    }

    struct node* temp = *head_first;

    if(position == 1){
        *head_first = temp->next;
        printf("Deleted %d from position %d.\n", temp->data, position);
        free(temp);
        return;
    }
    for(int i = 1; i < position-1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL){
        printf("Position is beyond the length of the list.\n");
        return;
    }
    struct node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    printf("Deleted %d from position %d.\n", nodeToDelete->data, position);
    free(nodeToDelete);
}

int searchNode(struct node* head, int value) {
    struct node* current = head;

    while (current != NULL) {
        if (current->data == value) return 1;
        current = current->next;
    }
    return 0;
}

void sortLinkedList(struct node* head) {
    struct node *current = head, *index = NULL;
    int temp_data;

    if(head == NULL){
        printf("List is empty.\n");
        return;
    }

    while(current != NULL) {
        index = current->next;

        while(index != NULL) {
            if(current->data > index->data) {
                temp_data = current->data;
                current->data = index->data;
                index->data = temp_data;
            }
            index = index->next;
        }
        current = current->next;
    }
    printf("List has been sorted.\n");
}

int main() {
    struct node* head = NULL;
    int choice, data, position, found;
    
    while(1) {
        printf("\nSingly Linked List Operations\n");
        printf("1. Print List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Position\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete from Position\n");
        printf("8. Search for Element\n");
        printf("9. Sort the List\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        if(scanf("%d", &choice)!=1){
            printf("Invalid input. Exiting.\n");
            break;
        }
        switch(choice){
            case 1:
                display(head);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 4:
                printf("Enter position to insert: ");
                scanf("%d", &position);
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtPosition(&head, data, position);
                break;
            case 5:
                deleteFromBeginning(&head);
                break;
            case 6:
                deleteFromEnd(&head);
                break;
            case 7:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 8:
                printf("Enter element to search: ");
                scanf("%d", &data);
                found = searchNode(head, data);
                if(found)
                    printf("Element %d found.\n", data);
                else
                    printf("Element %d not found.\n", data);
                break;
            case 9:
                sortLinkedList(head);
                break;
            case 10:
                return 1;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
