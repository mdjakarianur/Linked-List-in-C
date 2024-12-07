#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
void add(struct node** head, int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    
    if(*head==NULL){
        *head=newNode;
    }else{
        struct node* temp = *head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = newNode;
    }
}
void display(struct node* head){
    if(head==NULL){
        printf("LInkedList is empty.\n");
        return;
    }
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d ->", temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
void insert (struct node** head, int data, int position){
struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    struct node* temp = *head;
    for (int i=1; i<position -1 && temp!=NULL; i++){
        temp=temp->next;
    } 
    newNode->next=temp->next;
    temp->next=newNode;
}
void delete(struct node** head, int position){
    if(*head==NULL){
        printf("linkedList is empty.\n");
        return;
    }
    struct node* temp = *head;
    if(position==1){
        *head=temp->next;
        return;
    }
    for(int i=1; i<position-1&&temp!=NULL;i++){
        temp=temp->next;
    }
    struct node* toDelete = temp->next;
    temp->next=toDelete->next;
}

int search (struct node* head, int value){
    struct node* temp = head;
    while(temp!=NULL){
        if(temp->data==value) return 1;
            temp=temp->next;
        }
        return 0;
}
int main(){
    int found;
    struct node* head = NULL;
    add(&head,10);
    add(&head,20);
    add(&head,30);
    display(head);
    insert(&head,25,2);
    display(head);
    delete(&head,3);
    display(head);
    found = search(head,2);
                if (found)
                    printf("Found.\n");
                else
                    printf("Not Found.\n");
    return 0;
}
