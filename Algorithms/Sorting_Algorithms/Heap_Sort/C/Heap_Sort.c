//Program in C to implement heap sort algorithm

#include<stdio.h>

//swapping two numbers using call by reference
int swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
//Recursive function to heapify a subtree rooted with node i
//which is an index in array[],n being the no of elements
int maxHeapify(int array[],int n,int i)
{
    //initialise the largest number as the node
    int largest=i;
    //left child element
    int l=(2*i) + 1;
    //right child element
    int r=(2*i) + 2;

    //if left child is larger than the root
    if(l<n && array[l]>array[largest])
    {
        largest=l;
    }
    //if right child is larger than the largest so far
    if(r<n && array[r]>array[largest])
    {
        largest=r;
    }

    //if the largest element is not root element
    if(largest!=i)
    {
        //swap them
        swap(&array[largest],&array[i]);
        //recursively heapify the affected sub-tree
        maxHeapify(array,n,largest);
    }
}

//recursive function that implements heap sort
int heapSort(int array[],int n)
{
    //Building maximum heap(rearrangement of array)
    for(int i=(n/2)-1; i>=0; i--)
    {
        maxHeapify(array,n,i);
    }
    //Deleting maximum heap,one by one extraction
    for(int i=n-1; i>=0; i--)
    {
        //swap current root with end
        swap(&array[0],&array[i]);
        //Calling maxHeapify from root node(of reduced heap)because it gets deleted always
        maxHeapify(array,i,0);
    }
}
//Utility function to print the array
int printArray(int array[],int n)
{
    printf(" The sorted array is :\n");
    for(int i=0; i<n; ++i)
    {
        printf(" %d ",array[i]);
    }
}

//Driver program to check the above functions
int main()
{
    int array[]= {1,-11,2,16,7,22,0,-5};
    int n=8;
    heapSort(array,n);
    printArray(array,n);
    return 0;
}
