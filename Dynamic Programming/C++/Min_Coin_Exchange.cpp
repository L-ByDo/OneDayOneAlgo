//The minimum coin exchange problem focuses on finding the minimum number of coins we need to sum up to particular sum. Givven that we are supplied with unlimited quantity of coins. We apply dynamic programming approach to find out this solution

#include<iostream>
#include<algorithm>
using namespace std;
int find(int arr[],int n,int sum){
int subset[n+1][sum+1];
for(int i=0;i<=n;i++){   //loop through down the row which contains the value of each coin we have
    for(int j=0;j<=sum;j++){  //loop through the numbers untill the sum we need along the columns
        if(j==0){
            subset[i][j]=0;
        }
        else if(i==0){
            subset[i][j]=j;
        }
        else if(j<arr[i-1]){  //if value of sum we need is smaller, copy the value from above row
            subset[i][j]=subset[i-1][j];
        }
        else{  //else find minimum of above row value and the the value we obtain after subtracting the current value from the respective sum at current column
            subset[i][j]=min(subset[i-1][j],1+subset[i][j-arr[i-1]]);
        }
    }
}
return subset[n][sum];  //return last element of matrix
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
