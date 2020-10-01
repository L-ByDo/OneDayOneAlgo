//Program in C to impement merge sort algorithm
#include<stdio.h>

//Iterative function to merge individual list items into a list
//It returns the list sorted in ascending order
int merge(int array[],int lb,int mid,int ub)
{
    int i=lb,k=lb;
    int newarr[20];
    int j=mid+1;
    //for comparison of array[i] with array[j]
    while(i<=mid&&j<=ub)
    {
        if(array[i]<array[j])
        {
            newarr[k]=array[i];
            i++;
        }
        else
        {
            newarr[k]=array[j];
            j++;
        }
        k++;
    }
    //if array[i] gets exhausted,add array[j] list items
    if(i>mid)
    {
        newarr[k]=array[j];
        j++;
        k++;
    }
    else
    {
        //if array[j] gets exhausted,add array[i] list items
        while(i<=mid)
        {
            newarr[k]=array[i];
            i++;
            k++;
        }
    }
    //adding elements to the sorted list
    for(k=lb; k<=ub; k++)
    {
        array[k]=newarr[k];
    }
}

//divide list into halves recursively
int mergeSort(int array[],int lb,int ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        //dividing lists until a single list item remains
        mergeSort(array,lb,mid);
        mergeSort(array,mid+1,ub);
        //merging into a complete sorted list
        merge(array,lb,mid,ub);
    }
}

//Utility function to print the sorted array
int printArray(int array[],int lb,int ub)
{
    printf(" The required array after Sorting :\n");
    for(int i=lb; i<=ub; i++)
    {
        printf(" %d ",array[i]);
    }
}

//Driver program to check the above functions with sample input
int main()
{
    int array[]= {33,5,997,-4,0,18,7,-58};
    int lb=0;
    int ub=7;
    int mid=(lb+ub)/2;
    mergeSort(array,lb,ub);
    printArray(array,lb,ub);
    return 0;
}
