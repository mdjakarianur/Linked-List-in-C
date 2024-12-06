#include <stdio.h>

struct node {
    int data;
    struct node* next;
};

void add(struct node** head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insert(struct node** head, int data, int position) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position is out of range.\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void delete(struct node** head, int position) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = *head;

    if (position == 1) {
        *head = temp->next;
        return;
    }

    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position is out of range.\n");
        return;
    }

    struct node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
}

void display(struct node* head) {
    if (head == NULL) {
        printf("\nThe list is empty.\n");
        return;
    }

    struct node* temp = head;
    printf("\nLinkedList Elements Are:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void sort(struct node* head) {
    struct node *current = head, *index = NULL;
    int temp_data;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (current != NULL) {
        index = current->next;

        while (index != NULL) {
            if (current->data > index->data) {
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

int search(struct node* head, int value) {
    struct node* current = head;

    while (current != NULL) {
        if (current->data == value) return 1;
        current = current->next;
    }
    return 0;
}

int main() {
    struct node* head = NULL;
    int choice, data, position, found;

    while(1) {
        printf("\nLinkedList Operations\n");
        printf("1. Add\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Sort\n");
        printf("6. Search\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                add(&head, data);
                break;
            case 2:
                printf("Enter position to insert: ");
                scanf("%d", &position);
                printf("Enter data: ");
                scanf("%d", &data);
                insert(&head, data, position);
                break;
            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                delete(&head, position);
                break;

            case 4:
                display(head);
                break;
            case 5:
                sort(head);
                break;
            case 6:
                printf("Enter element to search: ");
                scanf("%d", &data);
                found = search(head, data);
                if (found)
                    printf("Element %d found.\n", data);
                else
                    printf("Element %d not found.\n", data);
                break;
            case 7:
                return 1;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
