//NAME-ANIRBAN BANERJEE
//REGISTRATION NUMBER-21BPS1061
//IMPLEMENTATION OF DOUBLE LINKED LIST

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
struct node* addatbeg(struct node* head,int data)//Function to add node at the begining of the List.
{
	struct node* temp=malloc(sizeof(struct node));
	temp->prev=NULL;
	temp->data=data;
	temp->next=NULL;
	
	temp->next=head;
	head->prev=temp;
	head=temp;
	return head;
}
struct node* addatend(struct node* head,int data)//Function to add node at the end of the List.
{
	struct node* temp=malloc(sizeof(struct node));
	temp->prev=NULL;
	temp->data=data;
	temp->next=NULL;
	struct node* ptr=head;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=temp;
	temp->prev=ptr;
	return head;
}
struct node* addinbetween(struct node* head,int data,int pos)//Function to add a node in between of the list.
{
   struct node *ptr = (struct node *)malloc(sizeof(struct node));  
   struct node *temp;   
   int i, loc=pos;   
    temp=head;  
    for(i=0;i<loc;i++)  
    {  
        temp = temp->next;  
        if(temp == NULL)  
        {  
            printf("\nCan't insert\n");  
            return;  
        }  
    }  
    ptr->data = data;  
    ptr->next = temp->next;  
    ptr -> prev = temp;  
    temp->next = ptr;  
    temp->next->prev=ptr;  
    printf("Node Inserted\n");
	return head;  
}
struct node* createlist(struct node* head)
{
	int i,data,node;
	printf("Enter the number of nodes to be inserted.\n");
	scanf("%d",&node);
	if(node==0){
		return head;
	}
	printf("Enter the element of the first node.\n");
	scanf("%d",&data);
	head=addtoempty(head,data);
	for(i=1;i<node;i++)
	{
		printf("Enter element of the %d node\n",i+1);
		scanf("%d",&data);
		head=addatend(head,data);
	}
	return head;
}
struct node* delfirst(struct node* head)//Function to delete first node.
{
	struct node* temp=head;
	head=head->next;
	free(temp);
	head->prev=NULL;
	return head;
}
struct node* dellast(struct node* head)//Function to delete last node.
{
	struct node* temp1=head;
	struct node* temp2;
	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
	}
	temp2=temp1->prev;
	temp2->next=NULL;
	free(temp1);
	return head;
}
struct node* print(struct node* head)//Function to print the Double Linked List.
{
	struct node* temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
int main()
{
	int data,pos,ch;
	struct node* head=malloc(sizeof(struct node));
	while(1)//Creating a infinite while loop
	{
		printf("Enter 1 to insert element.\nEnter 2 to insert element at the begining of the list.\nEnter 3 to insert element at a certain position in the list.\nEnter 4 to delete the first element of the list.\nEnter 5 to delete the last element of the list.\nEnter 6 to print the Double Linked List.\nEnter 7 to exit.\n");
		printf("Enter your choice.\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				head=createlist(head);
				printf("Element Inserted Successfully.\n");
				break;
			case 2:
				printf("Enter data\n");
				scanf("%d",&data);
				head=addatbeg(head,data);
				printf("Data Inserted Successfully.\n");
				break;
			case 3:
				printf("Enter element to be inserted.\n");
				scanf("%d",&data);
				printf("Enter the position to insert the data.\n");
				scanf("%d",&pos);
				head=addinbetween(head,data,pos);
				printf("Element Inserted Successfully.\n");
				break;
			case 4:
				head=delfirst(head);
				printf("First Element Deleted Successfully.\n");
				break;
			case 5:
				head=dellast(head);
				printf("Last element deleted successfully.\n");
				break;
			case 6:
				print(head);
				break;
			case 7:
				exit(1);
				
		}
		
	}
}
