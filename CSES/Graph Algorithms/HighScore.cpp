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

const long long int INF = 1e17;
const long long int NINF = INF * (-1);

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

long long int n, m;
#define ll long long int
vector<ll> dist;

void bellman_ford(vector<vector<ll>> edges)
{
    for (ll i = 2; i <= n; ++i)
    {
        dist[i] = INF;
    }
    for (ll i = 1; i < n; ++i)
    {
        for (auto e : edges)
        {
            ll u = e[0];
            ll v = e[1];
            ll d = e[2];
            if (dist[u] == INF)
                continue;
            dist[v] = min(dist[v], d + dist[u]);
            dist[v] = max(dist[v], NINF);
        }
    } // n relaxations

    for (ll i = 1; i < n; ++i)
    {
        for (auto e : edges)
        {

            ll u = e[0];
            ll v = e[1];
            ll d = e[2];
            if (dist[u] == INF)
                continue;
            dist[v] = max(dist[v], NINF);
            if (dist[u] + d < dist[v])
            {
                dist[v] = NINF;
            }
        }
    }

}

int main()
{
    //OJ;
    cin >> n >> m;
    dist.resize(n+1);
    vector<vector<ll>> edges;
    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        c = (c * (-1));
        edges.push_back({a, b, c});
    }

    bellman_ford(edges);
    if (dist[n] == NINF)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << dist[n] * (-1) << endl;
}
