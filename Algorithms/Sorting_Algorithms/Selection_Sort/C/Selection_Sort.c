//Program in C to implement Selection Sort algorithm

#include<stdio.h>

//Utility function to implement selection sort.
//It returns the sorted array in ascending order.

int swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
int selectionSort(int array[],int n)
{
    int min,i;
    for(i=0; i<n-1; i++)
    {
        //Initialise first element as the minimum element
        min=i;
        //Working on unsorted array
        for(int j=i+1; j<n; j++)
        {
            //Checking which one is smaller
            if(array[j]<array[min])
                min=j;
        }

        //if min!=i,we swap them
        if(min!=i)
            //Using call by reference
            swap(&array[i],&array[min]);

    }
}
//Utility function to print array
int printArray(int array[],int n)
{
    printf(" The sorted array is :\t");
    for(int i=0; i<n; i++)
    {
        printf(" %d ",array[i]);
    }
}

//Driver function to utilise the above functions
int main()
{
    //Sample input
    int array[]= {7,-2,5,-44,101,38};
    int n=6;
    selectionSort(array,n);
    printArray(array,n);

    return 0;
}
