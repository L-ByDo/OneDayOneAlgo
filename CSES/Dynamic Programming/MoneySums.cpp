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
   int n;
   cin >> n;
   int* arr = new int[n];
   int sum = 0;
   for(int i=0; i<n; i++){
       cin >> arr[i];
       sum+=arr[i];
   }

   vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
   dp[0][0] = true;

   for(int i=1; i<=n; i++){
       for(int j=0; j<=sum; j++){
           dp[i][j] = dp[i-1][j];
           int left = j-arr[i-1];
           if(left>=0 && dp[i-1][left]){
               dp[i][j] = true;
           }
       }
   }

   vector<int> possible;
   for(int i=1; i<=sum; i++){
       if(dp[n][i]){
           possible.push_back(i);
       }
   }

   cout << possible.size() << endl;
   for(int i=0; i<possible.size(); i++){
       cout << possible[i] << " ";
   }

   cout << endl;


   
}