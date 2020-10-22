#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <set>
#include <algorithm>
using namespace std;

#define ll long long int

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int main()
{
    //OJ;   
    ll n;
    cin >> n;
    ll* arr = new ll[n];
    ll sum = 0;
    for(ll i=0; i<n; i++){
        cin >> arr[i];
        sum+=arr[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(n));
    for(int l = n-1; l>=0; l--){
        for(int r=l; r<n; r++){
            if(l==r){
                dp[l][r] = arr[l];
            }
            else {
                dp[l][r] = max(arr[l]-dp[l+1][r], arr[r]-dp[l][r-1]);
            }
        }
    }

    cout << (sum+dp[0][n-1])/2 << endl;

}