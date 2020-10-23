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
    OJ;
    FIO;
    ll n;
    cin >> n;
    ll* arr = new ll[n];
    for(ll i=0; i<n; i++){
        cin >> arr[i];
    }
    map<ll, ll> m = {{0,1}};
    ll sum=0, ans=0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
        sum = ((sum%n)+n)%n;
        cout << sum << endl;
        if(m.count(sum)){
            ans+=m[sum];
        }
        m[sum]++;
    }

    cout << ans << endl;
}
    