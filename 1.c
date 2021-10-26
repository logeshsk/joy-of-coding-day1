#include<stdlib.h>
#include<stdio.h>
struct arr{
	int num;
	int count;
};
typedef struct arr arr;
void accept(int n,arr *a)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Enter element\n");
		scanf("%d",&(a[i].num));
		a[i].count=1;
	}
}
void check(int n,arr *a)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(a[i].num==a[j].num)
				{
					printf("Array is not unique\n");
					return;
				}
	printf("Array is unique\n");
}
void count(int n,arr *a)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if((a[i].num==a[j].num)&&a[i].count!=-1)
			{
				(a[i].count)++;
				(a[j].count)=-1;
			}
	for(i=0;i<n;i++)
		if(a[i].count!=-1)
			printf("%d's count : %d\n",a[i].num,a[i].count);		
}
void main()
{
	int i,n;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	arr* a=(arr*)malloc(n*(sizeof(arr)));
	accept(n,a);
	check(n,a);
	count(n,a);
}
