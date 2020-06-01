//Program in c to implement insertion sort algorithm

#include<stdio.h>
//Iterative Function to demonstrate insertion sort
//It returns the array sorted in ascending order
int insertionSort(int array[],int n)
{
	//For traversing the unsorted sublist
	for(int i=1;i<n;i++)
	{
		int temp=array[i];
		int j=i-1;
		while(j>=0&&array[j]>temp)
		{
			//shifting element towards right
			array[j+1]=array[j];
			j--;
		}
		//inserting element into appropriate position
		array[j+1]=temp;
	}
} 
//Utility function to print the array
int printArray(int array[],int n)
{
	printf("The required array after sorting :\n");
	for(int i=0;i<n;i++)
	{
		printf(" %d ",array[i]);
	}
}

//Driver program to check the above functions
int main()
{
	int array[]={5,8,-11,99,27,0};
	int n=6;
	insertionSort(array,n);
	printArray(array,n);
	return 0;
}
