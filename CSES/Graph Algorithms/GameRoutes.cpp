#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <climits>
#include <set>
#include <queue>
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

int mod = 1e9 + 7;
int n, m;
vector<int> parent;
vector<set<int>> g;
vector<int> dist;
vector<bool> visited;
vector<int> cnt;
vector<int> wt;
vector<int> inDegree;

void dfs()
{
    queue<int> q;
    for (int i = 2; i <= n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : g[u])
        {
            --inDegree[v];
            if (inDegree[v] == 0)
            {
                q.push(v);
            }
        }
    }

    q.push(1);
    cnt[1] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : g[u])
        {
            --inDegree[v];
            cnt[v] = cnt[v] + cnt[u];
            cnt[v] %= mod;
            if (inDegree[v] == 0)
            {
                q.push(v);
            }
        }
    }
}

int main()
{
    //OJ;
    cin >> n >> m;
    cnt.resize(n + 1);
    inDegree.resize(n + 1);
    g.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        ++inDegree[b];
    }

    dfs();
    cout << cnt[n] << endl;
}
