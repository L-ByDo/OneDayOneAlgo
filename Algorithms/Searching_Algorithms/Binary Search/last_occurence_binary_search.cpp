/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int arr[8]={1,2,3,3,3,3,3,4};
    int low=0;
    int high=7;
    int x=3;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==x && arr[mid]<arr[mid+1]){ //if next element is greater and mid element is equal,we found
            cout<<mid;
            break;
        }
        else if(arr[mid]<x){  //else search left
            high=mid-1;
        }
        else{  //else search right
            low=mid+1;
        }
    }

    return 0;
}
