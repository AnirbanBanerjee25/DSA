//Implementation of Queue using single Linked List.
#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node* link;
};struct node *rear=NULL,*front=NULL;
void enqueue(int n)
{
	struct node* temp=malloc(sizeof(struct node));
	temp->data=n;
	temp->link=NULL;
	if(rear==NULL)
	{
		front=rear=temp;
	}
	else
	{
		rear->link=temp;
		rear=temp;
	}
	
}
int dequeue()
{
	int data;
	struct node* temp;
	if(isempty())
	{
		printf("Empty\n");
		exit(1);
	}
	
	temp=front;
	data=temp->data;
	front=front->link;
	free(temp);
	temp=NULL;
	return data;
	
}
int isempty()
{
	if(front==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void print()
{
	if(isempty())
	{
		printf("queue is empty");
		exit(1);
	}
	else
	{
		struct node* temp=front;
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->link;
		}
		
	}
}
int main()
{
	enqueue(52);
	enqueue(62);
	enqueue(72);
	dequeue();
	print();
}
