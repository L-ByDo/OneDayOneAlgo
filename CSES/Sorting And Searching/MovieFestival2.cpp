#include <iostream>
#include <vector>
#include<set>
#include<algorithm>
using namespace std;

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int n,k;
vector<pair<int ,int>> v;
multiset<int> m;

int main() {
    OJ;
    cin >> n >> k;
    v.resize(n);
    for(int i=0; i<n; i++) {
        cin >> v[i].first >> v[i].second;
        swap(v[i].first,v[i].second);
    }
    sort(v.begin(), v.end());
    for(int i=0;i<k; i++) m.insert(0);
    int ans = 0;
    for(auto t: v) {
        auto it = m.upper_bound(t.second);
        //cout << t.second << endl;
        if (it == m.begin()) continue;
      //cout << "TESSS" << endl;
        m.erase(prev(it)); m.insert(t.first); ans ++;// Hum jab aye, usse phle kitni movies khatam hogyin, agar position kahi beech  ki h, to ek movie remove kro, or apne jane ka time add kro, mtln humne usse phle ek movie or dekh skte hain.
    }
    cout << ans << endl;
}