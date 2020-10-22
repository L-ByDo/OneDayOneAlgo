#include <iostream>
#include<queue>
#include<algorithm>
using namespace std;

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
    long long int n;
    cin >> n;
    vector<pair<long long int,long long int>> v;
    long long int a, b;
    while(n--){
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

    sort(v.begin(), v.end());
    long long int max_ans = 0, curr_ans = 0;
    for(int i=0; i<v.size(); i++){
        curr_ans+= v[i].first;
        max_ans += (v[i].second-curr_ans);
    }

    cout << max_ans << endl;

    return 0;
}