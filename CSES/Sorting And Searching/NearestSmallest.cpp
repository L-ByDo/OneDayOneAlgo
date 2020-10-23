#include <iostream>
#include <queue>
#include<map>
#include<stack>
using namespace std;

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long int

class myComp
{
public:
    int operator() (pair<ll, ll> p1, pair<ll, ll> p2)
    {
        
    }
};
int main()
{
   // OJ;
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v;
    for(ll i=0; i<n; i++){
        ll x;
        cin >> x;
        v.push_back({x, i+1});
    }

    stack<pair<ll, ll>> stk;    
    for(ll i=0; i<n; i++){
        while(!stk.empty()  && (stk.top().first >= v[i].first)){
            stk.pop();
        }
        if(stk.empty()){
            cout << 0 << " ";
        } else {
            cout << stk.top().second << " ";
        }

        stk.push(v[i]);
    }
    cout << endl;
    
    return 0;
}