#include <stdio.h>
#include <stdlib.h>
struct node
{
	struct node* prev;
	int data;
	struct node* next;
};
struct node* delfirst(struct node* head)//Deleting first element of List
{
	struct node* temp=head;
	head=head->next;
	free(temp);
	temp=NULL;
	head->prev=NULL;
	return head;
}
struct node* dellast(struct node* head)
{
	struct node* temp=head;
	struct node* temp2;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp2=temp->prev;
	temp2->next=NULL;
	free(temp);
	return head;
}
struct node* addtoempty(struct node* head,int data)
{
	struct node* temp=malloc(sizeof(struct node));
	temp->prev=NULL;
	temp->data=data;
	temp->next=NULL;
	head=temp;
	return head;
}
struct node* addatend(struct node* head,int data)
{
	struct node* temp=malloc(sizeof(struct node));
	struct node* ptr;
	temp->prev=NULL;
	temp->data=data;
	temp->next=NULL;
	ptr=head;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=temp;
	temp->prev=ptr;
	return head;
	
}
struct node* createlist(struct node* head)
{
	int node,data,i;
	printf("Enter no of nodes\n");
	scanf("%d",&node);
	if(node==0)
	{
		return head;
	}
	printf("Enter the element of node 1:\n");
	scanf("%d",&data);
	head=addtoempty(head,data);
	for(i=1;i<node;i++)
	{
		printf("Enter element of node %d: ",i+1);
		scanf("%d",&data);
		head=addatend(head,data);
	}
	return head;
}
struct node* print(struct node* head)
{
	struct node* ptr=head;
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->data);
		ptr=ptr->next;
	}	
}
int main()
{
	struct node* head=malloc(sizeof(struct node));
	struct node* ptr;
	head=createlist(head);
	ptr=head;
	printf("Double Linked List Created is:\n");
    print(head);
    
	printf("Double Linked List after deletion at begining is:\n");
	head=delfirst(head);
	print(head);
	
	printf("Double Linked List after deletion at end is:\n");
	head=dellast(head);
	print(head);
	
	return 0;
}

