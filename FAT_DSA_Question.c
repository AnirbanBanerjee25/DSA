/*Store n numbers in a linked list sort it. Put the nos which are armstrong in a array, construct a BST with the array
and print the BST in INORDER.*/
//Anirban Banerjee
#include <stdio.h>
#include <stdlib.h>
struct tree* newtree(int data);
void addnode(int data);
void sort(int n);
int check(int data);
void armstrong();
void getsize(int count);
void isarm();
void print_armstrong(int a[]);
void print();
struct tree* insertnode(struct tree* ptr,int data);
void inorder(struct tree* newp);
void inorder(struct tree* newp);

int size;
int a[];
struct node
{
	int data;
	struct node* link;
};
struct node *head,*tail=NULL;
struct tree
{
	int data;
	struct node* left;
	struct node* right;
};
struct tree* newtree(int data)
{
	struct tree* branch=malloc(sizeof(struct tree));
	branch->data=data;
	branch->left=NULL;
	branch->right=NULL;
	return (branch);
}

void addnode(int data)
{
	struct node* newnode=malloc(sizeof(struct node));
	newnode->data=data;
	newnode->link=NULL;
	if(head==NULL)
	{
		head=newnode;
		tail=newnode;
	}
	else
	{
		tail->link=newnode;
		tail=newnode;
	}
}
void sort(int n)
{
	struct node* current=head;
	struct node* index=NULL;
	int t;
	if(head==NULL)
	{
		return;
	}
	else
	{
		while(current!=NULL)
		{
			index=current->link;
			while(index!=NULL)
			{
				if(current->data>index->data)
				{
					t=current->data;
					current->data=index->data;
					index->data=t;
				}
				index=index->link;
			}
			current=current->link;
		}
	}
}
int check(int data)
{
	int d=0;
	int sum=0;
	int temp=data;
	while(data>0)
	{
		d=data%10;
		sum=sum+(d*d*d);
		data=data/10;
	}
	if(sum==temp)
	{
		return 1;
	}
	else{
		return 0;
	}
}
void armstrong()
{
	int data,i=0;
	int count=0;
	struct node* temp=head;
	while(temp!=NULL)
	{
		data=temp->data;
		if(check(data)==1)
		{
			count++;
		}
		temp=temp->link;
	}
	printf("Number of Armstrong numbers is= %d\n",count);
	getsize(count);
	
}
void getsize(int count)
{
	size=count;
}
void isarm()
{
	int data;
	int i=0;
	struct node* temp=head;
	while(temp!=NULL)
	{
		data=temp->data;
		if(check(data)==1)
		{
			a[i++]=data;
		}
		temp=temp->link;
	}
	print_armstrong(a);
}
void print_armstrong(int a[])
{
	int i;
	printf("Armstrong numbers are:\n");
	for(i=0;i<size;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
void print()
{
	struct node* temp=head;
	printf("Linked List elements are:\n");
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->link;
	}
	printf("\n");
}
struct tree* insertnode(struct tree* ptr,int data)
{
	if(ptr==NULL)
	{
		ptr=newtree(data);
		return ptr;
	}
	else if(data>ptr->data)
	{
		ptr->right=insertnode(ptr->right,data);
	}
	else if(data<ptr->data)
	{
		ptr->left=insertnode(ptr->left,data);
	}
}
void inorder(struct tree* newp)
{
	if(newp!=NULL)
	{
		inorder(newp->left);
		printf("%d ",newp->data);
		inorder(newp->right);
	}
}
int main()
{
	struct tree* p=NULL;
	int n;
	printf("Enter count:\n");
	scanf("%d",&n);
	int i,data;
	for(i=0;i<n;i++)
	{
		printf("Enter data\n");
		scanf("%d",&data);
		addnode(data);
	}
	sort(n);//Sorts the linked list
	armstrong();
	isarm();//To check for armstrong numbers
	print();//To print the sorted linked list.
	for(i=0;i<size;i++)
	{
		p=insertnode(p,a[i]);
	}
	printf("Inorder traversal of the binary tree is:\n");
	inorder(p);
	return 0;
}
