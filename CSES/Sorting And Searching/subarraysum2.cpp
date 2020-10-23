#include <iostream>
#include<map>
using namespace std;
 
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long int
 
int main()
{
  // OJ;
    FIO;
    ll n, target;
    cin >>n>> target;
    ll* arr = new ll[n];
    for(ll i=0; i<n; i++){
        cin >> arr[i];
    }
    ll sum = 0, ans = 0;
    map<ll, int> m = {{0, 1}};
    for(int i=0; i<n; i++){
        sum+=arr[i];
        if(m.count(sum-target)){
            ans+=m[sum-target];
        }
        m[sum]++;
    }

    cout << ans << endl;

}
    