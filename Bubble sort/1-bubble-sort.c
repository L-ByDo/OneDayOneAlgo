#include<conio.h>
#include<stdio.h>
void main()
{
    int i,n,arr[100],j,temp;
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    printf("ENter the elements in the array");
    for(i=1;i<=n;i++)
    {
        scanf("\t %d",&arr[i]);

    }
    printf("Elements before sorting:" );
    for ( i = 1; i <= n; i++)
    {
        printf("\t %d",arr[i]);
    }
    for ( i=1; i<=n-1; i++)
    {
        for ( j=1; j<=n-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        
    }
    printf("\n Elements after sorting are:");
    for ( i=1; i<=n; i++)
    {
        printf("\t %d",arr[i]);
    }
    
}