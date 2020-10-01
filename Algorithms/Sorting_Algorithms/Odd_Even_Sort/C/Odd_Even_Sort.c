//Program in C to implement Odd-Even Sort Algorithm
#include<stdio.h>
//A function to sort the elements using Odd-Even Sort
//Here,sorting is done in ascending order
int OddEvenSort(int array[],int terms)
{
	//Performing Bubble Sort on odd-indexed elements 
	for(int i=1;i<=terms-2;i+=2)
	{
		for(int j=i;j>=0;j--)
		{
			if(array[j]>array[j+1])
			{
				int temp=array[j+1];
				array[j+1]=array[j];
				array[j]=temp;
			}	
		}
	}
	
	//Performing Bubble Sort on even-indexed elements
	for(int i=0;i<=terms-2;i+=2)
	{
		for(int j=i;j>=0;j--)
		{
			if(array[j]>array[j+1])
			{
				int temp=array[j+1];
				array[j+1]=array[j];
				array[j]=temp;
			}	
		}
	} 
}
//Utility function to print the array
int PrintArray(int array[],int terms)
{
	printf("\nArray after sorting :\n");
	for(int i=0;i<terms;i++)
	{
		printf("%d ",array[i]);
	}
}
//Driver Program to check the above functions
int main()
{
	//Sample Input
	int array[]={4,9,11,-7,0,3,88,43};
	int n=8;
	printf("Array before sorting :\n");
	for(int i=0;i<8;i++)
	{
		printf("%d ",array[i]);
	}
	OddEvenSort(array,n);
	PrintArray(array,n);
return 0;
}
