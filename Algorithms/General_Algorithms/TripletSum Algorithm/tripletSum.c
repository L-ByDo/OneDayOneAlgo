#include <stdio.h> 

bool tripletSum(int array[], int arr_size, int sum) 
{ 
	int l, r; 

	for (int i = 0; i < arr_size - 2; i++) { 

		for (int j = i + 1; j < arr_size - 1; j++) { 

			for (int k = j + 1; k < arr_size; k++) { 
				if (array[i] + array[j] + array[k] == sum) { 
					printf("Triplet is %d, %d, %d", 
						array[i], array[j], array[k]); 
					return true; 
				} 
			} 
		} 
	} 

	return false; 
} 

int main() 
{ 
	int array[100];
	int sum,i,arr_size;
  	printf("Size of array:");
  	n=scanf("%d",&arr_size);
  	printf("Sum for triplet you are looking for:");
  	n=scanf("%d",&sum);
  	
  	for(i=0;i<n;i++){
    	printf("enter %dth value",i);
      	sacnf("%d",&array[i]);
    }
 
	tripletSum(array, arr_size, sum); 
	return 0; 
} 
