#include <iostream>
#include <vector>
#include<climits>
#include<algorithm>
#include<set>
#include<set>
using namespace std;

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define ll long long int


void max_sum_subarray(vector<ll> arr, ll L, ll R) 
{ 
    ll n = arr.size(); 
    ll* pre = new ll[n]{0}; 
    pre[0] = arr[0]; 
    for (ll i = 1; i < n; i++) { 
        pre[i] = pre[i - 1] + arr[i]; 
    } 
    multiset<ll> s1; 
    s1.insert(0); 
    ll ans = INT64_MIN; 
    ans = max(ans, pre[L - 1]); 
    ll flag = 0; 
  
    for (ll i = L; i < n; i++) { 
        if (i - R >= 0) { 
            if (flag == 0) { 
                auto it = s1.find(0); 
                s1.erase(it); 
                flag = 1; 
            } 
        } 
        s1.insert(pre[i - L]);  
        ans = max(ans, pre[i] - *s1.begin()); 
        if (i - R >= 0) { 
            auto it = s1.find(pre[i - R]); 
            s1.erase(it); 
        } 
    } 
    cout << ans << endl; 
} 

int main() {
   // OJ;
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n);
    for(ll i=0; i<n ;i++){
        cin >> v[i];
    }

    max_sum_subarray(v, a, b);
}