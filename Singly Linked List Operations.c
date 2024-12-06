#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node* next;
};

// Function to print the linked list
void printList(struct node* head) {
    struct node* temp = head;
    printf("\nList elements are:\n");
    while(temp != NULL) {
        printf("%d", temp->data);
        if(temp->next != NULL)
            printf(" ---> ");
        temp = temp->next;
    }
    printf(" ---> NULL\n");
}

// Function to insert a node at the beginning
void insertAtBeginning(struct node** head_ref, int new_data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = new_data;
    newNode->next = *head_ref;
    *head_ref = newNode;
    printf("Inserted %d at the beginning.\n", new_data);
}

// Function to insert a node at the end
void insertAtEnd(struct node** head_ref, int new_data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = new_data;
    newNode->next = NULL;

    if(*head_ref == NULL){
        *head_ref = newNode;
        printf("Inserted %d as the first element.\n", new_data);
        return;
    }

    struct node* temp = *head_ref;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Inserted %d at the end.\n", new_data);
}

// Function to insert a node at a specific position
void insertAtPosition(struct node** head_ref, int new_data, int position) {
    if(position < 1){
        printf("Position should be >= 1.\n");
        return;
    }

    if(position == 1){
        insertAtBeginning(head_ref, new_data);
        return;
    }

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = new_data;

    struct node* temp = *head_ref;
    for(int i = 1; i < position-1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Position is beyond the length of the list.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d.\n", new_data, position);
}

// Function to delete a node from the beginning
void deleteFromBeginning(struct node** head_ref) {
    if(*head_ref == NULL){
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    printf("Deleted %d from the beginning.\n", temp->data);
    free(temp);
}

// Function to delete a node from the end
void deleteFromEnd(struct node** head_ref) {
    if(*head_ref == NULL){
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if((*head_ref)->next == NULL){
        printf("Deleted %d from the end.\n", (*head_ref)->data);
        free(*head_ref);
        *head_ref = NULL;
        return;
    }

    struct node* temp = *head_ref;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    printf("Deleted %d from the end.\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

// Function to delete a node from a specific position
void deleteAtPosition(struct node** head_ref, int position) {
    if(*head_ref == NULL){
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if(position < 1){
        printf("Position should be >= 1.\n");
        return;
    }

    struct node* temp = *head_ref;

    if(position == 1){
        *head_ref = temp->next;
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

// Function to search for a node with given key
bool searchNode(struct node* head, int key) {
    struct node* current = head;

    while (current != NULL) {
        if (current->data == key) return true;
        current = current->next;
    }
    return false;
}

// Function to sort the linked list
void sortLinkedList(struct node* head) {
    struct node *current = head, *index = NULL;
    int temp_data;

    if(head == NULL){
        printf("List is empty. Nothing to sort.\n");
        return;
    }

    while(current != NULL) {
        index = current->next;

        while(index != NULL) {
            if(current->data > index->data) {
                // Swap data
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

// Function to free the entire list
void freeList(struct node** head_ref){
    struct node* current = *head_ref;
    struct node* next_node;

    while(current != NULL){
        next_node = current->next;
        free(current);
        current = next_node;
    }
    *head_ref = NULL;
}

// Main function to demonstrate linked list operations
int main() {
    struct node* head = NULL;
    int choice, data, position;
    bool found;

    while(1) {
        printf("\n--- Singly Linked List Operations ---\n");
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
                printList(head);
                break;
            case 2:
                printf("Enter data to insert at beginning: ");
                if(scanf("%d", &data)!=1){
                    printf("Invalid input.\n");
                    break;
                }
                insertAtBeginning(&head, data);
                break;
            case 3:
                printf("Enter data to insert at end: ");
                if(scanf("%d", &data)!=1){
                    printf("Invalid input.\n");
                    break;
                }
                insertAtEnd(&head, data);
                break;
            case 4:
                printf("Enter data to insert: ");
                if(scanf("%d", &data)!=1){
                    printf("Invalid input.\n");
                    break;
                }
                printf("Enter position to insert: ");
                if(scanf("%d", &position)!=1){
                    printf("Invalid input.\n");
                    break;
                }
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
                if(scanf("%d", &position)!=1){
                    printf("Invalid input.\n");
                    break;
                }
                deleteAtPosition(&head, position);
                break;
            case 8:
                printf("Enter element to search: ");
                if(scanf("%d", &data)!=1){
                    printf("Invalid input.\n");
                    break;
                }
                found = searchNode(head, data);
                if(found)
                    printf("Element %d found in the list.\n", data);
                else
                    printf("Element %d not found in the list.\n", data);
                break;
            case 9:
                sortLinkedList(head);
                break;
            case 10:
                freeList(&head);
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
