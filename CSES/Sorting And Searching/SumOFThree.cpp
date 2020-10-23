#include <iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>
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
    long long int n, target;
    cin >> n >> target;
    vector<pair<long long int,long long int>> v;
    for(long long int i=0; i<n; i++){
        long long int num;
        cin >> num;
        v.push_back({num, i+1});
    }

    sort(v.begin(), v.end());
    for(long long int i=0; i<n-2; i++){
        long long int low = i+1;
        long long int high = n-1;
        while(low<high){
            int sum = v[i].first + v[low].first + v[high].first;
            if(sum == target){
                cout << v[i].second << " " << v[low].second << " " << v[high].second << endl;
                return 0;
            } else if(sum < target){
                low+=1;
            } else {
                high-=1;
            }
        }        
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}