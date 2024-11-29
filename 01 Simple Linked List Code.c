#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node *next;
};
int main(){
	struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;
	printf("size = %d \n", sizeof(int));
	printf("size of Node = %d \n", sizeof(struct Node));
	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));
	printf("Address of first node = %d , Address of second node = %d ,Address of third node = %d \n",head,second,third);
	head->data = 1;
	head->next = second; 
	second->data = 2;
	second->next = third;
	third->data = 3;
	third->next = NULL;
	printf("Start = %d\n",head);
	printf("Data in Start = %d\n",head->data);
	printf("Pointer in first Node = %d\n",head->next);
	printf("Second = %d\n",second);
	printf("Data in Second Node = %d\n",second->data);
	printf("Pointer in Second Node = %d\n",second->next);
	printf("Third = %d\n",third);
	printf("Data in Third Node = %d\n",third->data);
	printf("Pointer in Third Node = %d\n",third->next);
	printf("[%d]  [%d][%d]   [%d][%d]   [%d][%d]",head,head->data,head->next,second->data,second->next,third->data,third->next);
	return 0;
}

