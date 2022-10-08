//Implementation of stacks using linked list.
#include <stdio.h>
#include <stdlib.h>
void push(int );
int pop();
int peek();
void print();
struct node
{
	int data;
	struct node* link;
}*top=NULL;
int isempty()
{
	if(top==NULL){
		return 1;
	}
	else{
		return 0;
	}
}
int peek()
{
	if(top==NULL)
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	else{
		return top->data;
	}
}
int pop()
{
	struct node* temp;
	int val;
	if(isempty()){
		printf("Stack Underflow\n");
		exit(1);
	}
	temp=top;
	val=temp->data;
	top=top->link;
	free(temp);
	temp=NULL;
	return val;
	
}
void push(int data)
{
	struct node* newnode;
	newnode=malloc(sizeof(newnode));
	if(newnode==NULL)
	{
		printf("Stack Overflow");
		exit(1);
	}
	newnode->data=data;
	newnode->link=NULL;
	newnode->link=top;
	top=newnode;
}
void print()
{
	struct node* temp;
	temp=top;
	if(isempty()){
		printf("Stack Underflow\n");
		exit(1);
	}
	printf("The stack elements are:\n");
	while(temp){
		printf("%d ",temp->data);
		temp=temp->link;
	}
	printf("\n");
}
int main()
{
	int choice,data;
	while(1)
	{
		printf("Enter 1 for push\n");
		printf("Enter 2 for pop\n");
		printf("Enter 3 to see peek\n");
		printf("Enter 4 for print\n");
		printf("Enter 5 for quit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter element to be pushed\n");
				scanf("%d",&data);
				push(data);
				break;
			case 2:
				data=pop();
				printf("Deleted element=%d\n",data);
				break;
			case 3:
				data=peek();
				printf("Peek element=%d",data);
				break;
			case 4:
				print();
				break;
			case 5:
				exit(1);
				break;
			default:
				printf("Invalid choice\n");
		}
	}
	return 0;
}
