//NAME - ANIRBAN BANERJEE
//REGISTRATION NUMBER - 21BPS1061
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	struct node* prev;
	int data;
	struct node* next;
}node;

typedef struct queue
{
	struct node* front;
	struct node* rear;
	int size;
}queue;
struct queue* getMyQueue()
{
    queue * ref = malloc(sizeof(queue));
    if (ref == NULL)
    {
        return NULL;
    }
    ref->front = NULL;
    ref->rear = NULL;
    
    return ref;
}
struct node* getnode(struct node* prev,int data)
{
	struct node* ref=malloc(sizeof(struct node));
	if(ref==NULL)
	{
		return NULL;
	}
	ref->data=data;
	ref->next=NULL;
	ref->prev=prev;
	return ref;
}
void enqueue(queue* ref,int data)
{
	node * node;
	node=getnode(ref->rear,data);
	if(ref->front==NULL)
	{
		ref->front=node;
		ref->size=1;
	}
	else
	{
		ref->rear->next=node;
		ref->size=ref->size+1;
	}
	ref->rear=node;
	
}
int isEmpty(queue* ref)
{
	if(ref->size==0)
	{
		return 1;
	}
	else{
		return 0;
	}
}
int peek(queue* ref)
{
	if(isEmpty(ref)==1)
	{
		printf("Empty Queue\n");
		return -1;
	}
	else{
		return (ref->front->data);
	}
}
int isSize(queue* ref)
{
	return ref->size;
}
int dequeue(queue* ref)
{
	if(isEmpty(ref)==1)
	{
		return -1;
	}
	else
	{
		int data=peek(ref);
		node* temp=ref->front;
		if(ref->front==ref->rear)
		{
			ref->front==NULL;
			ref->rear==NULL;
		}
		else
		{
			ref->front=ref->front->next;
			ref->front->prev=NULL;
		}
		ref->size--;
		return data;
	}
}
void printQdata(queue * ref)
{
    node * node = ref->front;

    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
int main()
{
	struct queue* q = getMyQueue();
    int ch,data;
    while(1)
    {
    	printf("Enter 1 for Enqueue\nEnter 2 for Dequeue\nEnter 3 to display peek element\nEnter 4 to check if queue is empty\nEnter 5 to display size of the queue\nEnter 6 to print the queue\nEnter 7 to exit\n");
    	printf("Enter your choice\n");
    	scanf("%d",&ch);
    	switch(ch)
    	{
    		case 1:
    			printf("Enter element to be inserted\n");
    			scanf("%d",&data);
    			enqueue(q,data);
    			printf("Element inserted successfully\n");
    			break;
    		case 2:
    			data=dequeue(q);
    			printf("Element Dequeued= %d\n",data);
    			break;
    		case 3:
    			data=peek(q);
    			printf("Peek Element = %d\n",data);
    			break;
    		case 4:
    			if(isEmpty(q)==1)
    			{
    				printf("Queue is empty\n");
				}
				else{
					printf("Queue is not empty\n");
				}
				break;
			case 5:
				data=isSize(q);
				printf("Size of queue is: %d\n",data);
				break;
			case 6:
				printf("Elements of Queue are:\n");
				printQdata(q);
				break;
			case 7:
				exit(1);
		}
	}
	return 0;
}

