#include<iostream>
#include<algorithm>
using namespace std;
int find(int arr[],int n,int sum){
int subset[n+1][sum+1];
for(int i=0;i<=n;i++){
    for(int j=0;j<=sum;j++){
        if(j==0){
            subset[i][j]=0;
        }
        else if(i==0){
            subset[i][j]=j;
        }
        else if(j<arr[i-1]){
            subset[i][j]=subset[i-1][j];
        }
        else{
            subset[i][j]=min(subset[i-1][j],1+subset[i][j-arr[i-1]]);
        }
    }
}
return subset[n][sum];
}
int main(){
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
int sum=10;
cout<<find(arr,n,sum);
}
