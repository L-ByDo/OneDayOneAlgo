#include <iostream>
#include<algorithm>
#include<vector>
#include<map>
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
    FIO;
    int n, x, y, curr_end = 0, total = 0;
    vector<pair<int, int>> arr;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        arr.push_back(make_pair(y, x));
    }

    sort(arr.begin(), arr.end());
    for(auto ele: arr){
        if(ele.second >= curr_end){
            curr_end = ele.first;
            total++;
        }
    }

    cout << total << endl;
    return 0;
}