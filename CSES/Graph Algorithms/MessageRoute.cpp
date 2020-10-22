#include <iostream>
#include <vector>
#include <list>
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

bool visited[100001] = {false};
list<int> adj[100001];
int parent[100001];
int n, m;

void dfs(int index)
{
    if(index == n){
        return;
    }
    visited[index] = true;
    for (auto a : adj[index])
    {
        if (visited[a] == false)
        {
            parent[a] = index;
            visited[a] = true;
            dfs(a);
        }
    }
}

int main()
{
    OJ;
    FIO;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        visited[p] = true;
        if (p == n)
            break;
        for (int aa : adj[p])
        {
            if (visited[aa] == false)
            {
                parent[aa] = p;
                visited[aa] = true;
                q.push(aa);
            }
        }
    }

    //dfs(1); //We want shortest path, therefore we are not using dfs, and using bfs
    if (visited[n] == false)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        int end = n;
        vector<int> ans;
        ans.push_back(n);
        while (end != 1)
        {
            end = parent[end];
            ans.push_back(end);
        }
        cout << ans.size() << endl;
        for(int i=ans.size()-1; i>=0; i--){
            cout << ans[i] << " ";
        }
    }
}
