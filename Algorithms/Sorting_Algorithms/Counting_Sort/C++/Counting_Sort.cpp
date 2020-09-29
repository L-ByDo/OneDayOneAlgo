#include <iostream>

using namespace std;
void countingsort(int arr[],int size){
    int count[10],j,i,B[size];
    for(i=0;i<10;i++){
        count[i]=0;
    }
    for(j=0;j<size;j++){
    count[arr[j]]=count[arr[j]]+1;
    }
    for(i=1;i<10;i++){
        count[i]=count[i-1]+count[i];
    }
    for(j=size-1;j>=0;j--){
        B[count[arr[j]]-1]=arr[j];
        count[arr[j]]=count[arr[j]]-1;
    }
    for(int k=0;k<size;k++){
        cout<<B[k];
    }

}

int main()
{
    int size,range=10;
    cout<<"Enter size of array";
    cin>>size;
    int myarray[size];
    cout<<"Enter integers from 0 to 9";
    for(int i=0;i<size;i++){
        cin>>myarray[i];
    }
    countingsort(myarray,size);
}
