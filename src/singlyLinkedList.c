#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
}*start = NULL;


void insertNodeAtStart(){
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	int data;

	newnode->next = start;
	start = newnode;
	printf("Enter the node data");
	scanf("%d",&data);
	newnode->data = data;
}

void traverseNode(){
	struct node *temp= start;
	printf("\nThe content of the list is : ");
	while(NULL != temp){
		printf("%d\t",temp->data);
		temp = temp->next;
	}
}

void freeNodes(){
	struct node *temp= start;
	
	while(NULL != temp){
		start = temp->next;
		free(temp);
		temp = start;
	}

}

void insertAtPosition(int position){
	struct node *temp= start;
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	int i = 0;
	int data;

	if( 1 == position )
		start = newnode;


	while(i < position-2){
		printf("\n%d",i);
		temp = temp->next;
		i++;
	}

	printf("Enter the node data");
	scanf("%d",&data);

	newnode->next = temp->next;
	temp->next = newnode;
	newnode->data = data;

}

void insertNodeAtEnd(){
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	struct node *temp= start;
	int data;
	
	while(NULL != temp->next){
		temp = temp->next;
	}
	printf("Enter the node data");
	scanf("%d",&data);
	temp->next = newnode;
	newnode->data = data;
	newnode->next = NULL;

}

int main(){
int choice;
int position;

while(1){
printf("\nEnter 1 to insert node at Start\n2 to insert node at the End\n3 to enter at a particular location\n4 to free the heap");
scanf("%d",&choice);
	switch(choice){
		case 1:
		insertNodeAtStart();
		traverseNode();
		break;

		case 2:
		insertNodeAtEnd();
		traverseNode();
		break;

		case 3:
		printf("\nEnter the position of the node : ");
		scanf("%d",&position);

		insertAtPosition(position);
		traverseNode();
		break;

		case 4:
		freeNodes();
		traverseNode();
		break;
	}
}

return 0;
}
