//Anirban Banerjee
//Insertion sort
#include <stdio.h>
#include <stdlib.h>
void insertsort(int *,int );
void print(int *,int );
int main()
{
	int n,i;
	printf("Enter number of elements\n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter elements into the array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	insertsort(arr,n);
	printf("Elements after merge sort are\n");
	print(arr,n);
}
void insertsort(int *a,int n)
{
	int i,j;
	int key;
	for(i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;
		while(j>=0 && a[j]>key)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
		
	}
}
void print(int *a,int nm)
{
	int i;
	for(i=0;i<nm;i++)
	{
		printf("%d\n",a[i]);
	}
}
