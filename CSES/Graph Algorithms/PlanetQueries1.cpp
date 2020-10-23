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

int n, m, q;


int main()
{
    OJ;
    cin >> n >> q;
    int ances[205][30];
    for(int i=1; i<=n; i++){
        cin >> ances[i][0];
    }
    for(int j=1; j<30; j++){
        for(int i=1; i<=n; i++){
            ances[i][j] = ances[ances[i][j-1]][j-1];
        }
    }

    for(int i=0; i<q; i++) {
        int x,k;
        cin >> x >> k;
        for(int j=29; j>=0; j--){
            if(k&(1<<j)){
                x = ances[x][j];
            }
        }
        cout << x << endl;
    }

}
