//Anirban Banerjee
//Check for Balanced Brackets in an expression (well-formedness) using Stack.
#include <stdio.h>
#include <stdlib.h>
#define bool int
struct sNode{
	char data;
	struct sNode* next; 
};
void push(struct sNode** ,int );
int pop(struct sNode** );
bool isMatchingPair(char ch1,char ch2)
{
	if(ch1=='(' && ch2==')'){
		return 1;
	}
	else if(ch1=='{' && ch2=='}'){
		return 1;
	}
	else if(ch1=='[' && ch2==']'){
		return 1;
	}
	else{
		return 0;
	}
}
bool arebalanced(char exp[]){
	int i=0;
	struct sNode* stack=NULL;
	while(exp[i]){
		if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
			push(&stack,exp[i]);
		}
		if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
			if(stack==NULL)
			{
				return 0;
			}
			else if(!isMatchingPair(pop(&stack),exp[i])){
				return 0;
			}
		}
		i++;
	}
	if (stack==NULL){
		return 1;
	}
	else{
		return 0;
	}
}
int main()
{
	char exp[100]="{()}[]";
	if(arebalanced(exp))
	{
		printf("BALANCED\n");
	}
	else{
		printf("NOT BALANCED\n");
	}
	return 0;
}
void push(struct sNode** top_ref,int new_data)
{
	struct sNode* newnode=(struct sNode*)malloc(sizeof(struct sNode));
	if(newnode==NULL)
	{
		printf("OVERFLOW");
		getchar();
		exit(0);
	}
	newnode->data=new_data;
	newnode->next=(*top_ref);
	(*top_ref)=newnode;
}
int pop(struct sNode** top_ref)
{
	char res;
	struct sNode* top;
	if(*top_ref==NULL)
	{
		printf("UNDERFLOW\n");
		getchar();
		exit(0);
	}
	else{
		top=*top_ref;
		res=top->data;
		*top_ref=top->next;
		free(top);
		return res;
	}
}


