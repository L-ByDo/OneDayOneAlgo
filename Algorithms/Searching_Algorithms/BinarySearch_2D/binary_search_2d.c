#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROW_INDEX i;
#define COL_INDEX j;

/*
 * Function: binarySearch
 * ----------------------
 * checks ITERATIVELY for for the target value in array and prints the index if found +
 * the number of comparisons made.
 * 
 * *array: pointer to the array
 * rows: total number of rows
 * columns: total number of columns
 * target_value: value that needs to be searched in the arary.
 * 
*/
void binarySearch(int *array, int rows, int cols, int target_value){

    int start = 0, comparisonsCount = 0;
    int mid, i, j, value;
    int end = rows * cols - 1;  // total number of elements - 1

    // loop for the given condition
    while(start <= end){

        comparisonsCount++;     // increment of number of comparisons

        mid = (start + end) / 2;
        i = mid / cols;         // gives the ROW_INDEX of middle element
        j = mid % cols;         // gives the COLUMN_INDEX of middle element
        value = *((array + i*cols) + j);    // value at the given ROW & COLUMN INDEX

        // Check if the target_value is same as middle value
        if (value == target_value){
            printf("Element found at index: %d, %d \n", i, j);
            printf("Number of Comparisons done: %d \n", comparisonsCount);
            return;
        }

        // If target_value is smaller than mid, then 
        // it can only be present in left subarray 
        else if(value > target_value) 
            end = mid - 1;

        // Else the element can only be present 
        // in right subarray 
        else
            start = mid + 1;
    }
    // If no matching target_value is found
    printf("Oops! No such element found in the array! \nTotal comparisons made: %d\n",comparisonsCount);
    return;
}

int main(void){

    // input size of array (integer)
    int rows, columns;
    printf("Enter number of rows and columns:\n");
    scanf("%d%d", &rows, &columns);

    // Initialize seed for Psuedo random number generator
    srand(time(0));

    // add random numbers to the array using rand() function
    int i, j, array[rows][columns];
    array[0][0] = rand() % 100;     // intitate the base value

    for (i = 0; i < rows; i++)
    {
        // If first row,
        if (i == 0)
        {
            for (j = 1; j < columns; j++)
            {
                array[i][j] = array[i][j - 1] + rand() % 100;
            }
        }

        // If not first Row
        else
        {
            for (j = 0; j < columns; j++)
            {
                // If condition for rows other than the firs tone
                // Each time row changes , 
                // assign value of the first element of next row such that
                // value of this element is more than that of last element of previous row  
                if (j == 0)
                {
                    array[i][0] = array[i - 1][columns - 1] + rand() % 100;
                }
                array[i][j] = array[i][j - 1] + rand() % 100;
            }
        }
    }

    // print array
    for (i=0; i<rows; i++){
        for(j=0; j<columns; j++){
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }

    printf("*****************************\n");

    //input the number to be searched
    printf("Your randomly sorted array is ready!Enter a number below to search. \n");
    int target;
    scanf("%d", &target);

    // Binary Search by passing the base address of the array
    binarySearch((int *)array, rows, columns, target);

    return 0;
}
