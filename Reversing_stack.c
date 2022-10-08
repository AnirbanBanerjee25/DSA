//Reversing a stack using two temporary stacks.
#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node* link;
};
void push(int d,struct node** top)//top is a pointer to a pointer
{
	struct node* newnode;
	newnode=malloc(sizeof(newnode));
	if(newnode==NULL)
	{
		printf("Stack Overflow");
		exit(1);
	}
	newnode->data=d;
	newnode->link=NULL;
	
	newnode->link=*top;// top means value stored in top and *top means go the location of the value and access that value. 
	*top=newnode;
}
int pop(struct node** top)
{
	struct node* temp;
	int val;
	temp= *top;
	val=temp->data;
	*top= (*top)->link;
	free(temp);
	temp=NULL;
	return val;
}
void print(struct node** top)
{
	struct node* temp;
	temp=*top;
	printf("Stack elements are:\n");
	while(temp)
	{
		printf("%d ",temp->data);
		temp=temp->link;
	}
	printf("\n");
}
int main()
{
	int data;
	struct node* top=NULL;
	struct node* top1=NULL;
	struct node* top2=NULL;
	
	//To original stack
	push(1,&top);
	push(2,&top);
	push(3,&top);
	
	//From original stack to temporary stack1.
	data=pop(&top);
	push(data,&top1);
	data=pop(&top);
	push(data,&top1);
	data=pop(&top);
	push(data,&top1);
	
	print(&top);
	print(&top1);
	
	//From temporary stack1 to temporary stack2
	data=pop(&top1);
	push(data,&top2);
	data=pop(&top1);
	push(data,&top2);
	data=pop(&top1);
	push(data,&top2);
	
	print(&top1);
	print(&top2);
	
	//From temporary stack2 to original stack
	data=pop(&top2);
	push(data,&top);
	data=pop(&top2);
	push(data,&top);
	data=pop(&top2);
	push(data,&top);
	
	print(&top2);
	print(&top);
}
