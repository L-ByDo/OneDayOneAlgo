#include <iostream>
#include <vector>
#include <list>
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

bool visited[100001] = {false};
bool recstack[100001] = {false};
list<int> adj[100001];
int parent[100001];
int n, m, sv, ev;

bool dfs(int i, int p)
{
    visited[i] = true;
    parent[i] = p;
    for (auto v : adj[i])
    {
        if (v == p)
        {
            continue;
        }

        if (visited[v])
        {
            sv = v;
            ev = i;
            return true;
        }

        if (!visited[v])
        {
            if (dfs(v, i))
            {
                return true;
            }
        }
    }

    return false;
}

bool isCyclic()
{
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, -1))
            {
                int tv = ev;
                ans.push_back(ev);
                while (tv != sv)
                {
                    ans.push_back(parent[tv]);
                    tv = parent[tv];
                }
                ans.push_back(ev);
                cout << ans.size() << endl;
                for (int i = 0; i < ans.size(); i++)
                {
                    cout << ans[i] << " ";
                }
                cout << endl;
                return true;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return false;
}

int main()
{
    //OJ;
    FIO;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    isCyclic();
}
