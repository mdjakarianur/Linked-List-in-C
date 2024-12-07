#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node*next;
};
void add(struct node** head, int data){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    
    if(*head==NULL){
        *head=newNode;
    }else{
    struct node* temp = *head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    }
}
void display(struct node* head){
    if (head==NULL){
        printf("Empty");
        return;
    }
    struct node* temp = head;
    while(temp!=NULL){
        printf("%d -> ", temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
void insert(struct node** head, int data, int position){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    struct node* temp=*head;
    for(int i=1;i<position-1&&temp!=NULL;i++){
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}
void delete(struct node** head, int position){
    if(*head==NULL){
        printf("Empty");
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
    struct node* todelete = temp->next;
    temp->next=todelete->next;
    
}
void search(struct node** head, int value){
    struct node* temp = *head;
    while(temp!=NULL){
        if(temp->data==value){
            printf("Fuond");
            return;
        }
        temp=temp->next;
    }
    printf("Not Found");
}
int main(){
    struct node* head=NULL;
    add(&head,10);
    add(&head,20);
    display(head);
    insert(&head, 15,2);
    display(head);
    delete(&head, 2);
    display(head);
    search(&head, 5);
    
    return 0;
}
