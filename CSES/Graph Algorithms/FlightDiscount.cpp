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
#define pb push_back

void DijktraAlgo1(int src)
{
    for(ll i=2; i<=n; i++) dist[0][i] = INF;
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({0,1});
    while (!pq.empty()) {
        pll x = pq.top();
        pq.pop();
        for (auto a: adj[x.second])
            if (dist[0][a.first] > x.first+a.second)
                pq.push({dist[0][a.first] = x.first+a.second,a.first});
    }
}

void DijktraAlgo2(int src)
{
    for(ll i=1; i<n; i++) dist[1][i] = INF;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,n});
    while (!pq.empty()) {
        pll x = pq.top(); pq.pop();
        for (auto a: radj[x.second]) if (dist[1][a.first] > x.first+a.second)
            pq.push({dist[1][a.first] = x.first+a.second,a.first});
    }
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
        adj[a].push_back({b, c});
        radj[b].push_back({a, c});
    }

    DijktraAlgo1(1);
    DijktraAlgo2(n);
    ll ans = INT64_MAX;
    for(ll i=1; i<=n; i++){
        if(dist[0][i]!=INT64_MAX){
            for(auto a: adj[i]){
                if(dist[1][a.first]!=INT64_MAX){
                    ans = min(ans, dist[0][i]+dist[1][a.first]+(a.second/2));
                }
            }
        }
    }

    cout << ans << endl;
}
