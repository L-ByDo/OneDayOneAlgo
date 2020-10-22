#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <climits>
#include <set>
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
#define ll long long int
 
ll n, q;
vector<ll> child;
 
int main()
{
    //OJ;
    child.resize(n+1);
    cin >> n >> q;
    for(ll i=1; i<=n; i++){
        cin >> child[i];
    }
 
    for(ll i=0; i<q; i++){
        ll a, b;
        cin >> a >> b;
        vector<bool> vis(n+1, false);
        ll cnt = 0;
        ll flag = 0;
        while(a!=b){
            if(vis[a]){
                cout << -1 << endl;
                flag = 1;
                break;
            }
            if(a == child[a] && child[a] != b){
                cout << -1 << endl;
                flag = 1;
                break;
            }
            vis[a] = true;
            a = child[a];
            cnt++;
        }
 
        if(flag !=1){
           cout << cnt << endl;
        }
 
    }
}
    
 
 