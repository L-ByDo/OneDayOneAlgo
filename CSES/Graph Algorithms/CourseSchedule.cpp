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

int n, m;
vector<vector<int>> g;
vector<int> indegree;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    //OJ;
    cin >> n >> m;
    g.resize(n + 1);
    indegree.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        indegree[v]++;
    }

    for(int i=1; i<=n; i++){
        if(!indegree[i]){
            pq.push(i);
        }
    }

    vector<int> ans;
    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();
        ans.push_back(top);
        for(auto v: g[top]){
            indegree[v]--;
            if(!indegree[v]){
                pq.push(v);
            }
        }
    }

    if(ans.size()!=n){
        cout << "IMPOSSIBLE" << endl;
    } else {
        for(auto u: ans){
            cout << u << " ";
        }
        cout << endl;
    }
}
