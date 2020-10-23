#include <iostream>
#include <vector>
#include <map>
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

bool myComp(pair<int, pair<int, int>> A, pair<int, pair<int, int>> B)
{
    return A.second.second < B.second.second;
}

int main()
{
    OJ;
    int n;
    cin >> n;
    map<int, int> compress;
    vector<int> a(n), b(n), p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i] >> p[i];
        b[i]++;
        compress[a[i]], compress[b[i]];
    }

    int coords = 0;
    for (auto &v : compress)
    {
        v.second = coords++;
    }

    vector<vector<pair<int, int>>> project(coords);
    for (int i = 0; i < n; i++)
    {
        project[compress[b[i]]].emplace_back(compress[a[i]], p[i]);
    }

    vector<long long> dp(coords, 0);
    for (int i = 0; i < coords; i++)
    {
        if (i > 0)
        {
            dp[i] = dp[i - 1];
        }
        for (auto p : project[i])
        {
            dp[i] = max(dp[i], dp[p.first] + p.second);
        }
    }
    cout << dp[coords - 1] << endl;
}