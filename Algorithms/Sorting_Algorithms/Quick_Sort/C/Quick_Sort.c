//Program in C to demonstrate quick sort algorithm

#include<stdio.h>

//Utility function to swap the numbers using call by reference
int swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}

//Iterative utility function which does partion among the array elements
//Partition is done with respect to a pivot element
int partition(int array[],int lb,int ub)
{
	int start=lb;
	int end=ub;
	int pivot=array[lb];
	while(start<end)
	{
		//to the left of pivot,elements are less than or equal to it
		while(array[start]<=pivot)
		{
			start++;
		}
		//to the right of pivot,elements are greater than it
		while(array[end]>pivot)
		{
			end--;
		}
		//swap start with end only if start is less than end
		if(start<end)
		{
			swap(&array[start],&array[end]);
		}
	}
	//otherwise swap pivot with end
	swap(&array[lb],&array[end]);
	return end;
}

//Recursive utility function which returns the array sorted in ascending order
int quickSort(int array[],int lb,int ub)
{
	if(lb<ub)
	{
		//loc stores location of end so that we can break the array from pivot and proceed further
		int loc=partition(array,lb,ub);
		//recursive calls that sort the array further
		quickSort(array,lb,loc-1);
		quickSort(array,loc+1,ub);
	}
}

//Utility function to print the array
int printArray(int array[],int lb,int ub)
{
	printf(" The required sorted array :\n");
	for(int i=lb;i<=ub;i++)
	{
		printf(" %d ",array[i]);
	}
}

//Driver program to check the above functions
int main()
{
	int array[]={33,0,5,-9,227,84,2,-17};
	int lb=0,ub=7;
	quickSort(array,lb,ub);
	printArray(array,lb,ub);
	return 0;
}
