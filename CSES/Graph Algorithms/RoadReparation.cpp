#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define ll long long int
ll n, m;
vector<pair<ll, ll>> *l;

ll primAlgo(){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    bool* visited = new bool[n+1]{0};

    ll ans = 0;

    pq.push({0, 1});
    while(!pq.empty()){
        auto best = pq.top();
        pq.pop();
        
        ll to = best.second;
        ll weight = best.first;

        if(visited[to]){
            continue;
        }

        ans+= weight;
        visited[to] = true;

        for(auto x: l[to]){
            if(visited[x.first]==false){
                pq.push({x.second, x.first});
            }
        }
    }

    for(ll i=1; i<=n; i++){
        if(!visited[i]){
            return -1;
        }
    }

    return ans;
}

int main()
{
    //OJ;
    FIO;
    cin >> n >> m;
    l = new vector<pair<ll, ll>>[n+1];
    for(ll i=0; i<m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        l[a].push_back({b, c});
        l[b].push_back({a, c});
    }

    ll ans = primAlgo();
    if(ans==-1){
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}