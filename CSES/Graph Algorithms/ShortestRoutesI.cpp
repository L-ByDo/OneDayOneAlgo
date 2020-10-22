#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#include <unordered_map>
#include<climits>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

long long int n, m;

#define ll long long int

#define rep(x, i, j) for (int x = i; x < j; x++)
#define pb push_back

unordered_map<ll, list<pair<ll, ll>>> Hashmap;

void dijktraAlgo(ll src){
    unordered_map<ll, ll> dist;
    for(int i=1; i<=n; i++){
        dist[i] = INT64_MAX;
    }

    dist[src] = 0;
    set<pair<ll, ll>> s;
    s.insert({0, src});
    while(!s.empty()){
        auto curr = *(s.begin());
        ll node = curr.second;
        ll nodeDest = curr.first;
        s.erase(s.begin());


        for(auto childPair: Hashmap[node]){
            if(nodeDest + childPair.second < dist[childPair.first]){
                ll dest = childPair.first;
                auto f = s.find(make_pair(dist[dest], dest));
                if(f!=s.end()){
                    s.erase(f);
                }

                dist[dest] = nodeDest + childPair.second;
                s.insert(make_pair(dist[dest], dest));
            }
        }
    }

    for(ll i=1; i<=n; i++){
        cout << dist[i] << " ";
    }
    cout << endl;
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
        Hashmap[a].push_back(make_pair(b, c));
    }

    dijktraAlgo(1);
}
