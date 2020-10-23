#include <iostream>
#include <vector>
#include <climits>
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
    int n, target;
    cin >> n >> target;
    vector<int> c(n);
    for (int &v : c)
        cin >> v;
        
    vector<int> dp(target + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= target; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - c[j] >= 0)
            {
                dp[i] = min(dp[i], dp[i - c[j]] + 1);
            }
        }
    }

    cout << (dp[target] == 1e9 ? -1 : dp[target]) << endl;
    return 0;
}