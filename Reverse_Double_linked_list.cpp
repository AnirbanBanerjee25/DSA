//To print the Double Linked List in reverse order.
#include <stdio.h>
#include <stdlib.h>
struct node
{
	struct node* prev;
	int data;
	struct node* next;
};
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
	struct node* ptr=head;
	temp->prev=NULL;
	temp->data=data;
	temp->next=NULL;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=temp;
	temp->prev=ptr;
	return head;
}
struct node* create(struct node* head)
{
	int data,node,i;
	printf("Enter Number of nodes\n");
	scanf("%d",&node);
	if(node==0)
	{
		return head;
	}
	printf("Enter element of first node\n");
	scanf("%d",&data);
	head=addtoempty(head,data);
	for(i=1;i<node;i++)
	{
		printf("Enter element of %d node\n",i+1);
		scanf("%d",&data);
		head=addatend(head,data);
	}
	return head;
}
struct node* print(struct node* head)
{
	int a[10];
	int i=0;
	struct node* ptr=head;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	printf("Reverse Double Linked List is:\n");
	while(ptr!=head)
	{
		printf("%d ",ptr->data);
		ptr=ptr->prev;
	}
	printf("%d",ptr->data);
}
int main()
{
	struct node* head=malloc(sizeof(struct node));
	head=create(head);
	print(head);
	return 0;
}
