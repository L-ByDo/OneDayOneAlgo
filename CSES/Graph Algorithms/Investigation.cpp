#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <climits>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

#define int long long int

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int n, m;
const int INF = 1e17;
const int modb = 1e9+7;
const int MAXN = 1e5+1;
vector<vector<pair<int,int>>> g(MAXN);
vector<int> cost(MAXN);
vector<int> route(MAXN);
vector<int> minF(MAXN);
vector<int> maxF(MAXN);


void djk(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    cost[1] = 0;
    route[1] = 1;
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        int u = x.second;
        int d = x.first;
        
        if(d > cost[u])
            continue;
        for(auto e: g[u]){
            int c = e.second;
            int v = e.first;
            
            if(c+d > cost[v]){
                continue;
            }
            if(c+d == cost[v]){
                (route[v]+=route[u])%=modb;
                minF[v] = min(minF[v], minF[u]+1);
                maxF[v] = max(maxF[v], maxF[u]+1);
            }
            if(c+d < cost[v]){
                cost[v] = c+d;
                route[v] = route[u];
                minF[v] = minF[u]+1;
                maxF[v] = maxF[u]+1;
                pq.push({cost[v], v});
            }

            
        } 
    }
}

int32_t main()
{
    //OJ;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }

    for(int i=2; i<=n; i++){
        cost[i] = INF;
    }

    djk();
    cout << cost[n] << " " << route[n] << " " << minF[n] << " " << maxF[n] << endl;
}
