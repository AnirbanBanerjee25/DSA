#include <stdio.h>
int main()
{
	int a[10];
	int i;
	printf("Enter elements\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	int n = sizeof(a) / sizeof(a[0]);  
	printf("Elements before quick sort are:\n");
	printarr(a,n);
	quick(a,0,n-1);
	printf("\n");
	printf("Elements after quicksort are\n");
	printarr(a,n);
}
int quick(int a[],int start,int end)
{
	if(start<end)
	{
		int p=partition(a,start,end);
		quick(a,start,p-1);
		quick(a,p+1,end);
	}
}
int partition(int a[],int start,int end)
{
	int pivot=a[end];
	int i=start-1;
	int t,j;
	for(j=start;j<=end-1;j++)
	{
		if(a[j]<pivot)
		{
			i++;
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	t=a[i+1];
	a[i+1]=a[end];
	a[end]=t;
	return (i+1);
}
void printarr(int a[],int end)
{
	int i;
	for(i=0;i<end;i++)
	{
		printf("%d ",a[i]);
	}
}
