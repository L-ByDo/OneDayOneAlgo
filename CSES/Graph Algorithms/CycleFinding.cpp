#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#include <unordered_map>
#include <climits>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

//MAN IN THE MIDDLE TYPE OF PROBLEM

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

long long int n, m;

#define ll long long int
#define pll pair<long, long>
vector<pair<int, int>> adj[200001], radj[200001];
const ll INF = 1e18;

#define rep(x, i, j) for (int x = i; x < j; x++)
ll dist[2][200001];
int parent[200001];
vector<pair<pair<int ,int>, int>> edges;
int vis[200001];
#define pb push_back
vector<int> z;
void backtrack(int x)
{

    while (!vis[x])
    {
        z.pb(x);
        vis[x] = 1;
        x = parent[x];
    }
    z.push_back(x);
    reverse(z.begin(), z.end());
    while (z.back() != z.front())
        z.pop_back();
    for (int i : z)
        cout << i << " ";
}

void negBellmanFord()
{
    ll *dist = new ll[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }

    dist[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (auto a : edges)
        {
            if (dist[a.first.first] < INF)
            {
                ll t = dist[a.first.first] + a.second;
                if (t < dist[a.first.second])
                {
                    dist[a.first.second] = t;
                    parent[a.first.second] = a.first.first;
                }
            }
        }
    }
    for (auto a : edges)
        if (dist[a.first.second] > dist[a.first.first] + a.second)
        {
            cout << "YES\n";
            backtrack(a.first.second);
            return;
        }
    cout << "NO";
}


int main()
{
    OJ;
    FIO;
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        edges.push_back({{a,b},c});
    }
    negBellmanFord();
    return 0;    
}
