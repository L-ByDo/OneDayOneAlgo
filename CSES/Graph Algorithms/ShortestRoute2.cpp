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


//FLOYD-WARSHALL ALGORITHM

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

long long int n, m, q;

#define ll long long int

ll mat[501][501];


int main()
{
    //OJ;
    ll a, b, c;
    ll inf = 1e18;
    cin >> n >> m >> q;
    for(ll i=0; i<=n; i++){
        for(ll j=0; j<=n; j++){
            mat[i][j] = inf;
        }

        mat[i][i] = 0;
    }
    for(ll i=0; i<m; i++){
        cin >> a >> b >> c;
        mat[a][b] = min(mat[a][b], c);
        mat[b][a] = min(mat[b][a], c);
    }

    for(ll k=1; k<=n; k++){
        for(ll i=1; i<=n; i++){
            for(ll j=1; j<=n ;j++){
                mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
            }
        }
    }

    for(ll i=0; i<q; i++){
        ll x, y;
        cin >> x >> y;
        if(mat[x][y] >= inf){
            cout << -1 << endl;
        } else {
            cout << mat[x][y] << endl;
        }
    }

    return 0;

}
