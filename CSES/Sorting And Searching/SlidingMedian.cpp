#include <iostream>
#include <queue>
#include<set>
#include <vector>
using namespace std;

#define ll long long int

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

vector<ll> findMedian(vector<ll> &a, int k){
        ll n=a.size();
        multiset<ll> m;
        for(ll i=0;i<k;i++)
            m.insert(a[i]);
        auto it=m.begin();
        for(ll i=0;i<k/2;i++)
            it++;
        ll med=*it;
        vector<ll> ans;
        for(ll i=k;i<n;i++){
            auto ij=it;
            ij--;
            if(k%2==0)
                if(*ij < *it){
                    ans.push_back(*ij);
                } else {
                    ans.push_back(*it);
                }
            else
                ans.push_back(*it);
            m.insert(a[i]);
            if(a[i]<*it)
                it--;
            if(a[i-k]<=*it)
                it++;
            m.erase(m.lower_bound(a[i-k]));
        }
        auto ij=it;
        ij--;
        if(k%2==0)
            if(*ij < *it){
                    ans.push_back(*ij);
                } else {
                    ans.push_back(*it);
                }
        else
            ans.push_back(*it);
        return ans;
}

int main()
{
    OJ;
    ll n, windowSize;
    cin >> n >> windowSize;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<ll> ans = findMedian(arr, windowSize);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    
    

    return 0;
}