// C program to implement Binary Search algorithm
#include <stdio.h> 

//A iterative binary search function.It returns location of target element in given array arr[l..r] if present,otherwise -1
//We are using an array that is sorted in ascending order. 

int binarySearch(int array[],int l,int r, int n, int target) 
{ 
	l=0;
	r=n-1;
	//Implementing Binary Search
	while (l <= r) 
	{ 
		int mid = (l+r)/ 2; 

		// Checking if target element is the middle element 
		if (array[mid] == target) 
			return mid; 

		// If target is greater, ignore left half 
		if (array[mid] < target) 
			l = mid + 1; 

		// If target is smaller, ignore right half 
		else
			r = mid - 1; 
	} 

	// if we reach here, then element was not present and we return -1
	return -1; 
} 

//Driver program to check the above function
int main(void) 
{ 
	int l,r;
	int array[] = {2,9,17,23,28,36,42,59,77,92}; 
	int n = 10; 
	int target = 77 ; 
	int result = binarySearch(array,l,r,n,target); 
	//checking whether 77 is present or not
	(result == -1) ? printf("Element is not present in array"): printf("Element is present at index %d",result); 
return 0; 
} 
