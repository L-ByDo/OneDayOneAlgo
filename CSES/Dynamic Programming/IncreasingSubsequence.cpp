#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <set>
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

int main()
{
    //OJ;
    int n;
    cin >> n;
    vector<int> dp;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if(it==dp.end()){
            dp.push_back(x);
        } else {
            *it = x;
        }
    }

    cout << dp.size() << endl;
}