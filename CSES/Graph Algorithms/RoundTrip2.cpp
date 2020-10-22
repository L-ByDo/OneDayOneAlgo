#include <iostream>
#include <vector>
#include <stack>
#include <list>
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

int n, m, sv, ev;
vector<int> vis;
stack<int> resStack;
vector<bool> rsFlag;
vector<set<int>> g;

bool dfs(int u)
{
    vis[u] = true;
    resStack.push(u);
    rsFlag[u] = true;
    for (auto v : g[u])
    {
        if (!vis[v])
        {
            if (dfs(v))
            {
                return true;
            }
        }

        if (rsFlag[v])
        {
            resStack.push(v);
            return true;
        }
    }

    resStack.pop();
    rsFlag[u] = false;
    return false;
}

void visit_all()
{
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
            if (dfs(i))
                break;
    }
}

int main()
{
    //OJ;
    FIO;
    cin >> n >> m;
    vis.resize(n + 1);
    rsFlag.resize(n + 1);
    g.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
    }

    visit_all();

    if (resStack.empty())
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        vector<int> ans;
        int temp = resStack.top();
        while (!resStack.empty())
        {
            ans.push_back(resStack.top());
            resStack.pop();
            if (ans.back() == temp && ans.size() != 1)
            {
                break;
            }
        }

        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (auto u : ans)
        {
            cout << u << " ";
        }
    }
}
