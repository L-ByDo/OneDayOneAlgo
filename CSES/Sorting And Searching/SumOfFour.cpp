#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

#define ll long long int

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define rep(i, a, b) for(int i = a; i < (b); ++i)

int main()
{
    //OJ;
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    } 
    map<int, pair<int, int>> R;
    rep(i, 0, n)
        rep(j, i+1, n)
            R[a[i]+a[j]]={i, j};
            rep(i, 0, n) rep(j, i+1, n) {
                int y=x-a[i]-a[j];
                if (y>0 && R.count(y) && R[y].first>j) {
                    cout << i+1 << " " << j+1 << " ";
                    cout << R[y].first+1 << " " << R[y].second+1 << '\n';
                    return 0;
                }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}