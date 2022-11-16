//Anirban Banerjee
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
char stack[max];
char infix[max];
char postfix[max];
int top=-1;
void print();
int precedence(char );
void intToPost();
void push(char );
char pop();
int space(char c)
{
	if(c==' ' || c=='\t'){
		return 1;
	}
	else
	{
		return 0;
	}
}
void print()
{
	int i=0;
	while(postfix[i]){
		printf("%c",postfix[i++]);
	}
	printf("\n");
}
int precedence(char symbol)
{
	switch(symbol)
	{
		case '^':
			return 3;
		case '/':
		case '*':
			return 2;
		case '+':
		case '-':
			return 1;
		default:
			return 0;
	}
}
void intToPost()
{
    int i,j=0;
    char symbol,next;
    for(i=0;i<strlen(infix);i++)
    {
        symbol=infix[i];
        if(!space(symbol)){
        switch(symbol)
        {
            case '(':
            	push(symbol);
            	break;
            case ')':
           		while((next=pop())!='(')
				   {
				   	
               		postfix[j++]=next;
            		}
            	break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
            	while(isEmpty() && precedence(stack[top])>=precedence(symbol)){
                	postfix[j++]=pop();
                }
            	push(symbol);
            	break;
            default:
            postfix[j++]=symbol;//if symbol is operand
            
        }
    }
   }
   while(!isEmpty())
   {
   	postfix[j++]=pop();
}
postfix[j]='\0';
}
void push(char c)
{
	if(top==max-1){
		printf("Stack Overflow\n");
		return;
		
	}
	top++;
	stack[top]=c;
}
char pop()
{
	char c;
	if(top==-1)
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	c=stack[top];
	top--;
	return c;
}
int isEmpty()
{
	if(top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	printf("Enter Infix Expression.\n");
    gets(infix);
    intToPost();
    printf("Postfix Expression is:\n");
    print();
    return 0;
}

