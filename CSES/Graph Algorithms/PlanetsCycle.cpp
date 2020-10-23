#include <iostream>
#include <vector>
using namespace std;


#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define ll long long int

ll n, q;
vector<ll> child(200001);

void dfs(ll i, vector<bool> &vis, ll &cnt){
    vis[i] = true;
    ll ch = child[i];
    if(!vis[ch]){
        cnt++;
        dfs(ch, vis, cnt);
    }
}

int main()
{
    //OJ;
    FIO;
    child.resize(n+1);
    cin >> n;
    for(ll i=1; i<=n; i++){
        cin >> child[i];
    }

    for(ll i=1; i<=n; i++){
        vector<bool> vis(n+1, false);
        ll cnt = 1;
        dfs(i, vis, cnt);
        cout << cnt << " ";
    }
    cout << endl;

    return 0;     


}
