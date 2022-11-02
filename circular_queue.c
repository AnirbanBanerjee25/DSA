//Creaing Circular Queue
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int cqueue[MAX];
int rear=-1;
int front=-1;
int enqueue(int );
int dequeue();
int peek();
int isFULL();
int isEmpty();
void print();

int peek()
{
	if(isEmpty())
	{
		printf("Queue Underflows\n");
		exit(1);
	}
	return cqueue[front];
}
int isFULL()
{
	if((front==0 && rear==MAX-1) || (front==rear+1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isEmpty()
{
	if(front==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int enqueue(int data)
{
	if(isFULL())
	{
		printf("Queue Overflow\n");
		exit(1);
	}
	if(front==-1)
	{
		front=0;
	}
	if(rear==MAX-1)
	{
		rear=0;
	}
	else{
		rear=rear+1;
	}
	cqueue[rear]=data;
}
int dequeue()
{
	int data;
	if(isEmpty())
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	data=cqueue[front];
	if(front==rear)
	{
		front=rear=-1;
	}
	if(front==MAX-1)
	{
		front=0;
	}
	else
	{
		front=front+1;
	}
	return data;
}
void print()
{
	if(isEmpty())
	{
		printf("Queue Underflows\n");
		exit(1);
	}
	int temp=front;
	if(front<=rear)
	{
		while(temp<=rear)
		{
			printf("%d ",cqueue[temp]);
			temp++;
		}
	}
	else
	{
		while(temp<=MAX-1)
		{
			printf("%d ",cqueue[temp]);
			temp++;
		}
		temp=0;
		while(temp<=rear)
		{
			printf("%d ",cqueue[temp]);
			temp++;
		}
	}
	printf("\n");
}
int main()
{
	int ch,data;
	while(1){
	printf("1.Insert\n");
	printf("2.Delete\n");
	printf("3.Print first element\n");
	printf("4.Print all elements\n");
	printf("5.Quit\n");
	printf("Enter your choice\n");
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1:
			printf("Enter element to insert\n");
			scanf("%d",&data);
			enqueue(data);
			break;
		case 2:
			data=dequeue();
			printf("Sucessfully deleted element %d\n",data);
			break;
		case 3:
			data=peek();
			printf("First element= %d\n",data);
			break;
		case 4:
			printf("Elements of the circular queue are:\n");
			print();
			break;
		case 5:
			exit(1);			
	}
}
}

