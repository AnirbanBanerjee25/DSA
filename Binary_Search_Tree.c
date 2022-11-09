//NAME - ANIRBAN BANERJEE
//REGISTRATION NUMBER - 21BPS1061

//IMPLEMENTATION OF BINARY SEARCH TREE USING LINKED LIST.

#include <stdio.h>
#include <stdlib.h>

struct node//Structure to create the BST
{
	int data;
	struct node *left,*right;
};
struct node* create(int item)//Function to create a new node in the BST.
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;
	temp->left=temp->right=NULL;
	return temp;
}
struct node* insert(struct node* node,int item)//Function to insert the new node created in the Binary Search Tree.
{
	if(node==NULL)
	{
		return create(item);
	}
	if(item < node->data)
	{
		node->left=insert(node->left,item);
	}
	else if(item > node->data)
	{
		node->right=insert(node->right,item);
	}
	return node;
}
struct node* minvalue(struct node* node)
{
	struct node* current=node;
	while(current && current->left!=NULL)//Loops down to find the leftmost leaf.
	{
		current=current->left;
	}
	return current;
}
struct node* deletenode(struct node *node,int val)
{
	if(node==NULL)
	{
		return node;
	}
	if(val<node->data)//If value entered in less than node data we will traverse the left subtree and delete the element.
	{
		node->left=deletenode(node->left,val);
	}
	else if(val>node->data)//If value entered is greater than node data we will traverse the right subtree and delete the element.
	{
		node->right=deletenode(node->right,val);
	}
	else{
		 if (node->left == NULL) {
            struct node* temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL) {
            struct node* temp = node->left;
            free(node);
            return temp;
        }
  
        
        struct node* temp = minvalue(node->right);

        node->data = temp->data;
  
        node->right = deletenode(node->right, temp->data);
    }
    return node;
}
void print(struct node* node)//Function to display the Binary Search Tree 
{
	if(node!=NULL)
	{
		print(node->left);
		printf("%d\n",node->data);
		print(node->right);
	}
}
int main()
{
	struct node* node=NULL;
	int ch,data;
	while(1)//Creating an infinite loop untill user enters 4.
	{
		printf("Enter 1 to insert node\nEnter 2 to delete node\nEnter 3 to print the Binary Search Tree in Inorder Traversal\nEnter 4 to exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter Data to be inserted\n");
				scanf("%d",&data);
				node=insert(node,data);
				printf("Data inserted successfully\n");
				break;
			case 2:
				printf("Enter value to be deleted\n");
				scanf("%d",&data);
				node=deletenode(node,data);
				printf("Node deleted successfully\n");
				break;
			case 3:
				printf("The Binary Search Tree in Inorder Traversal is:\n");
				print(node);
				break;
			case 4:
				exit(1);
		}
	}
	return 0;	
}


