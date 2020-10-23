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
    string a, b;
    cin >> a >> b;
    int na = a.size(), nb = b.size();
    vector<vector<int>> dp(na + 1, vector<int>(nb + 1, 1e9));
    dp[0][0] = 0;
    for(int i=0; i<=na; i++){
        for(int j=0; j<=nb; j++){
            if(i>0){
                dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
            }

            if(j>0){
                dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
            }

            if(i && j){
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]+(a[i-1]!=b[j-1]));
            }
        }
    }

    cout << dp[na][nb] << endl;
}