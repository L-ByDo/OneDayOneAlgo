//Program in C to implement Counting Sort algorithm
#include<stdio.h>

//Iterative function that sorts the given array in ascending order
int countingSort(int array[],int n,int range)
{
	//initialising count array with zeroes
	int count[range]={0};
	//initialising output array of size n
	int output[n];
	//counting the frequency of each element 
	for(int i=0;i<n;i++)
	{
		count[array[i]]++;
	}
	//updating count array such that it reflects the actual position of element in output array
	for(int i=1;i<=range;i++)
	{
		count[i]=count[i]+count[i-1];
	}
	//starting from the end,we are now storing elements into the output array
	//this will insure that the stability of the algorithm is maintained 
	//as the same element which comes latter will be stored latter and vice versa
	for(int i=n-1;i>=0;i--)
	{
		output[--count[array[i]]]=array[i];
	}
	//building the final output array
	for(int i=0;i<n;i++)
	{
		array[i]=output[i];
	}
}

//Utility function to print the sorted array
int printArray(int array[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf(" %d ",array[i]);
	}
}

//Driver program to check the above functions
int main()
{
	int array[]={2,1,4,0,2,5,4,0,8,7,0,9,7,1,6};
	int n=15;
	int range=9;
	countingSort(array,n,range);
	printf(" The sorted array is :\n");
	printArray(array,n);
	return 0;
}
