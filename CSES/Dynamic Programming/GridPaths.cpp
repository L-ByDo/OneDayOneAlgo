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
   // OJ;
    int n;
    cin >> n;
    char** grid = new char*[n];
    for(int i=0; i<n; i++){
        grid[i] = new char[n];
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
        }
    }
    if(grid[n-1][n-1] == '*'){
        cout << 0 << endl;
        return 0;
    }
    int mod = 1e9+7;

    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i-1>=0){
                //cout << "YES" << endl;
                if(grid[i-1][j]!='*'){
                    (dp[i][j]+=dp[i-1][j])%=mod;
                }
            }
            if(j-1>=0){
                 if(grid[i][j-1]!='*'){
                    (dp[i][j]+=dp[i][j-1])%=mod;
                }
            }
        }
    }

    cout << dp[n-1][n-1] << endl;
}