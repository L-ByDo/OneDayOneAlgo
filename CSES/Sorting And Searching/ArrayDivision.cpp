#include <iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
 
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long int

int n,k,a[500000];

bool ok(ll mid) {
    int num = 0, cur = 0;
    while (num < k && cur < n) {
        ll sum = 0;
        while (cur < n && sum+a[cur] <= mid) sum += a[cur++];
        num ++;
    }
    return cur == n;
}

int main(){
   //OJ;
	cin >> n >> k;
    ll sum = 0;
	for(ll i=0; i<n; i++){
        cin >> a[i];
        sum+=a[i];
    }

	ll lo = 0, hi = 1e18;
    while (lo < hi) {
        ll mid = (lo+hi)/2;
        if (ok(mid)) hi = mid;
        else lo = mid+1;
    }
    cout << lo << endl;;
	return 0;
}
    