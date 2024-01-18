#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *link;
};

struct node* addfront(struct node* head,int data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->link=NULL;
	head=temp;
	printf("Data inserted successfully!\n");
	return head;
}
struct node* addatend(struct node* head,int data)
{
	struct node* temp1=head;
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->link=NULL;
	while(temp1->link!=NULL)
	{
		temp1=temp1->link;
	}
	temp1->link=temp;
	printf("Data inserted successfully!\n");
	return head;
}
struct node* addatpos(struct node* head,int data,int pos)
{

	struct node* temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->link=NULL;
	
	if(pos==1)
	{
		temp->link=head;
		head=temp;
	}
	else{
		struct node* current=head;
		for(int i=1;i<pos-2 && current!=NULL;i++){
			current=current->link;
		}
		if(current==NULL){
			printf("Position not found in the list.\n");
		}
		else{
			temp->link=current->link;
		    current->link=temp;
		    printf("Data inserted successfully!\n");	
		}
	}
	return head;
}
struct node* delfirst(struct node* head)
{
	struct node* temp=head;
	if(head==NULL){
		printf("Linked List is already empty!\n");
	}
	else{
		head=head->link;
		free(temp);
		printf("Node deleted successfully!\n");
	}
	return head;
}
struct node* dellast(struct node* head){
	struct node* temp=head;
		if(head==NULL){
		printf("Linked List is already empty!\n");
	}
	else{
		while(temp->link->link!=NULL)
	    {
	     	temp=temp->link;
    	}
	    free(temp->link);
	    temp->link=NULL;
	    printf("Node deleted successfully!\n");
	}

	return head;
}
struct node* delpos(struct node* head)
{
	struct node* temp=head;
	int pos;
	printf("Enter position to delete the data: ");
	scanf("%d",&pos);
	int i;
	for(i=0;i<pos-2 && temp->link!=NULL;i++){
		temp=temp->link;
	}
	temp->link=temp->link->link;
	return head;
}
struct node* reverse(struct node* head)
{
	struct node* current=head;
	struct node *nextnode=NULL, *prevnode=NULL;
	while(current!=NULL){
		nextnode=current->link;
		current->link=prevnode;
		
		prevnode=current;
		current=nextnode;
	}
	head=prevnode;
	printf("Linked List reversed successfully!\n\n");
	return head;
}
void printlist(struct node* head)
{
	struct node* temp=head;
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->link;
	}
	printf("\n");
}
int main()
{
	struct node* head=NULL;
	int choice,data,pos;
	while(1)
	{
		printf("Enter 1 to insert data to the front of the linked list.\n\n");
		printf("Enter 2 to insert data to the end of the linked list.\n\n");
		printf("Enter 3 to insert data at a certain position in a linked list.\n\n");
		printf("Enter 4 to delete a node from the front of a linked list.\n\n");
		printf("Enter 5 to delete a node from the end of a linked list.\n\n");
		printf("Enter 6 to delete a node from a certain position in a linked list.\n\n");
		printf("Enter 7 to reverse the linked list.\n\n");
		printf("Enter 8 to print the linked list.\n\n");
		printf("Enter your choice\n\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter data: ");
				scanf("%d",&data);
				head=addfront(head,data);
				break;
			case 2:
				printf("Enter data: ");
				scanf("%d",&data);
				head=addatend(head,data);
				break;
			case 3:
				printf("Enter data: ");
				scanf("%d",&data);
				printf("Enter position to add the node: ");
				scanf("%d",&pos);
				head=addatpos(head,data,pos);
				break;
			case 4:
				head=delfirst(head);
				break;
			case 5:
				head=dellast(head);
				break;
			case 6:
				head=delpos(head);
				break;
			case 7:
				head=reverse(head);
				break;
			case 8:
				printlist(head);
				break;
			default:
				printf("Wrong Choice!");
		}
	}
}
