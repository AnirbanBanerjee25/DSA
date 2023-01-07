//Fractional Knapsack Problem

#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
struct item
{
	int value,weight;
	item(int value,int weight)
	{
		this->value=value;
		this->weight=weight;
	}
};
bool cmp(struct item a,struct item b)
{
	double d1=(double)a.value/(double)a.weight;
	double d2=(double)b.value/(double)b.weight;
	return d1>d2;
}
double fractional_knapsack(struct item arr[],int w,int n)
{
	sort(arr,arr+n,cmp);
	int i,res;
	res=0;
	for(i=0;i<n;i++)
	{
		if(arr[i].weight<w)
		{
			res+=arr[i].value;
			w=w-arr[i].weight;
		}
		else
		{
			res+=arr[i].value*((double)w/(double)arr[i].weight);
			break;
		}
	}
	return res;
}
int main()
{
	int w=50;
	item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
	int n=sizeof(arr)/sizeof(arr[0]);
	
	cout<<"Knapsack Value = "<<fractional_knapsack(arr,w,n)<<endl;
	return 0;
	
}
