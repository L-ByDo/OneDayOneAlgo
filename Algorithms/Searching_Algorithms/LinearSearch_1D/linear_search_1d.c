#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*
 * Function: linearSearch
 * ----------------------
 * checks RECURSIVELY for the target value in array and prints the index if found +
 * the number of comparisons made.
 * 
 * *array_ptr : pointer to the array
 * array_size : size of the array
 * target_value : value that needs to be searched in the arary.
 * 
 * returns: none;
*/
void linearSearch(int *array_ptr, int array_size,int target_value){

    int comparisonsCount = 0;          // Number of times the comparison is made

    for (int i=0; i<array_size; i++){

        // Check if the target_value is same as middle value    
        if(*array_ptr == target_value){

            printf("Element found at index: %d \n", i);
            printf("Number of Comparisons done: %d \n", comparisonsCount);
            return;

        }
        comparisonsCount++;
        array_ptr++;
    }
    printf("Oops! No such element found in the array! \nTotal comparisons made: %d\n",comparisonsCount);
    return; 
}

int main(){

    // input size of array (integer)
    int sizeOfArray;
    printf("Enter the Size of Array! \n");
    scanf("%d",&sizeOfArray);

    // Initialize seed for Psuedo random number generator
    srand(time(0));

    // add random numbers to the array using rand() function
    int index, array[sizeOfArray];
    array[0] = rand() % 100;    // intitate the base value

    for (index=1 ; index<sizeOfArray; index++){
        array[index] = array[index-1] + rand() % 100;
    }
    
    // print the arary
    for(index=0; index<sizeOfArray; index++){
        printf("%d\t",array[index]);
    }
    printf("\n*****************************\n");
    // input the number to be searched
    printf("Your randomly sorted array is ready!Enter a number below to search. \n");
    int target;
    scanf("%d", &target);

    // linear search
    linearSearch(array, sizeOfArray, target);

    
    return 0;
}