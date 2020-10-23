#include <iostream>
#include <queue>
#include <vector>
#include<algorithm>
#include <climits>
using namespace std;

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int main()
{
    long long int n, t;
    cin >> n >> t;
    long long int* arr = new long long int[n];
    long long int max = INT_MIN;
    for(long long int i=0; i<n; i++){
        cin >> arr[i];
        if(arr[i]>max){
            max = arr[i];
        }
    }
    long long int right = max*t+1, low = 0;
    long long int ans, curr_ans=0;
    while(low<=right){
        long long int mid = low + (right-low)/2;
        curr_ans = 0;
        for(long long int i=0; i<n; i++){
            curr_ans+= (mid/arr[i]);
            if(curr_ans>=t){
               break;
           }
        }
        if(curr_ans>=t){
            ans = mid;
            right = mid-1;
        } else {
            low = mid+1;
        }
    }
    cout << ans << endl;
    return 0;
}