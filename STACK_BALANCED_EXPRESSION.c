//To check for balanced brackets in an expression.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int top=-1;
int st[20];
void push(char b);
char pop();
int main()
{
	char a[20],t;
	int i,f=1;
	printf("Enter the expression\n");
	scanf("%s",&a);
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]=='{' || a[i]=='(' || a[i]=='[')
		{
			push(a[i]);
		}
		if(a[i]== '}' || a[i]==')' || a[i]==']')
		{
			if(top==-1){
				f=0;
			}
			else{
			t=pop();
			if(a[i]==')' && (t=='[' || t=='{')){
				f=0;
			}
			if(a[i]==']' && (t=='(' || t=='{')){
				f=0;
			}
			if(a[i]=='}' && (t=='(' || t=='[')){
				f=0;
			}
		}
	}
}

if(top>=0)
f=0;
if(f==0){
	printf("UNBALANCED EXPRESSEION\n");
}
else
{
	printf("BALANCED EXPRESSION\n");
}
}
void push(char b)
{
	top++;
	st[top]=b;
}
char pop()
{
	return (st[top--]);
}
