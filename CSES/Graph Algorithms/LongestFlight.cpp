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

int n, m;
vector<int> parent;
vector<set<pair<int, int>>> g;
vector<int> dist;

void dijkstra(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    parent[1] = -1;
    dist[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()){
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        for(auto e: g[u]){
            int v = e.first;
            int wt = e.second;

            if(dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    OJ;
    cin >> n >> m;
    g.resize(n+1);
    parent.resize(n+1);
    for(int i=1; i<=n; i++){
        parent[i] = -1;
    }
    dist.resize(n+1);
    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        g[a].insert({b, -1});
    }

    dijkstra();
    if(dist[n] == 0){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << 1 + (dist[n]*-1) << endl;
    vector<int> ans;
    int temp = n;
    while(temp!=-1){
        ans.push_back(temp);
        temp = parent[temp];
    }

    reverse(ans.begin(), ans.end());
    for(auto u: ans){
        cout << u << " ";
    }
    cout << endl;
}
