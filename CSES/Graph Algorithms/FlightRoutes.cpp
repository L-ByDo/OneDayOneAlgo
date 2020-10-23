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

long long int n, m, k;
#define ll long long int
#define pll pair<long, long>
const ll INF = 9e15;
#define rep(x, i, j) for (ll x = i; x < j; x++)
#define pb push_back

vector<vector<pair<ll, ll>>> edges;
vector<vector<ll>> dist;

void dijkstra(){
    priority_queue< pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});
    while(!pq.empty()){
        auto x = pq.top();
        ll distance = x.first;
        ll u = x.second;
        pq.pop();
        if(dist[u][k-1] < distance){
            continue;
        }

        for(auto g: edges[u]){
            ll v = g.first;
            ll c = g.second;

            if(dist[v][k-1] > c+distance){
                dist[v][k-1] = c+distance;
                pq.push({dist[v][k-1], v});
                sort(dist[v].begin(), dist[v].end());
            }
        }
    }
}


int main()
{
    //OJ;
    FIO;
    cin >> n >> m >> k;
    edges.resize(n+1);
    dist.resize(n+1);
    for(ll i=1; i<=n; i++){
        dist[i].resize(k);
        for(ll j=0; j<k; j++){
            dist[i][j] = INF;
        }
    }

    dist[1][0] = 0;
    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
    }
 

    dijkstra();
    for(ll i=0; i<k; i++){
        cout << dist[n][i] << " ";
    }
    cout << endl;
    return 0;    
}
