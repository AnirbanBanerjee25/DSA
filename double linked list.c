//Operations on a double linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
	struct node* prev;
	int data;
	struct node* next;
};
struct node* addatend(struct node*head,int data)
{
	struct node* ptr=head;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	struct node* temp=malloc(sizeof(struct node));
	temp->prev=NULL;
	temp->data=data;
	temp->next=NULL;
	ptr->next=temp;
	temp->prev=ptr;
	return head;
	
}
struct node* addtoempty(struct node*head,int data)
{
	struct node* temp=malloc(sizeof(struct node));
	temp->prev=NULL;//Creating a new node
	temp->data=data;
	temp->next=NULL;
	head=temp;
	return head;
}
struct node* addatpos(struct node* head,int data,int pos)
{
	struct node* newp=NULL;
	struct node* temp=head;
	struct node* temp2=NULL;
	newp=addtoempty(newp,data);
	
	while(pos!=1)
	{
		temp=temp->next;
		pos--;
	}
	if(temp->next==NULL)
	{
		temp->next=newp;
		newp->prev=temp;
	}
	else
	{
		temp2=temp->next;
		temp->next=newp;
		temp2->prev=newp;
		newp->next=temp2;
		newp->prev=temp;
	}
	return head;	
};
struct node* addatbeg(struct node* head,int data)
{
	struct node* temp=malloc(sizeof(struct node));
	temp->prev=NULL;//Creating a new node
	temp->data=data;
	temp->next=NULL;
	temp->next=head;
	head->prev=temp;
	head=temp;
	return head;
}
int main()
{
	int pos=2;
	struct node* head = NULL;
	struct node* ptr;
	head = addtoempty(head,45);
	head = addatbeg(head,55);
	head= addatend(head,95);
	head= addatpos(head,20,pos);
	ptr = head;
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->data);
		ptr=ptr->next;
	}
	return 0;
}
