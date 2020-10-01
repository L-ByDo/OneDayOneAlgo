//Program in C to implement radix sort algorithm
//The program returns the array sorted in ascending order
#include<stdio.h>

//Function to get the maximum element inside the array
int getMaxElement(int array[],int n)
{
    int max=array[0];
    for(int i=0; i<n; i++)
    {
        if(array[i]>max)
        {
            max=array[i];
        }
    }
    return max;
}
//iterative function to apply count sort by place value(starting from one's place)
int countSort(int array[],int n,int pos)
{
    //initializing count array with zeroes
    int count[10]= {0};
    //output array
    int output[n],i;
    for(i=0; i<n; i++)
    {
        //inserting frequency of occurence
        count[(array[i]/pos)%10]++;
    }
    //increasing cumulatively which depicts the actual position of each digit
    for(i=1; i<10; i++)
    {
        count[i]+=count[i-1];
    }
    //entering values into the count array
    for(i=n-1; i>=0; i--)
    {
        output[count[ (array[i]/pos)%10 ] - 1] = array[i];
        count[ (array[i]/pos)%10 ]--;
    }
    //copying output array to get our final sorted array
    for(i=0; i<n; i++)
    {
        array[i]=output[i];
    }
}

//Recursive function to implement radix sort
int radixSort(int array[],int n)
{
    int max=getMaxElement(array,n);
    //position here depicts the place value(1 for ones place,etc)
    //Do counting sort for every digit.pos is 10^i
    //where i is current digit number
    for(int pos=1; (max/pos)>0; pos*=10)
    {
        countSort(array,n,pos);
    }
}

//Utility function to print the sorted array
int printArray(int array[],int n)
{
    printf(" The sorted array is :\n");
    for(int i=0; i<n; i++)
    {
        printf(" %d ",array[i]);
    }
}

//Driver program to check the above functions
int main()
{
    int array[6]= {232,77,122,9,982,65};
    int n=6;
    radixSort(array,n);
    printArray(array,n);
    return 0;
}
