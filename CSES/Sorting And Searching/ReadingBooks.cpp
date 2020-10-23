#include <iostream>
#include <algorithm>
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
   // OJ;
    long long int n;
    cin>>n;
    long long int* arr = new long long int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr, arr+n);
    long long int sum = 0;
    for(int i=0; i<n; i++){
        sum+= arr[i];
    }

    cout << max(sum, 2*arr[n-1]) << endl;

    return 0;
}
