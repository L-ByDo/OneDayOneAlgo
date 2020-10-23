#include <iostream>
#include <vector>
#include<cstring>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

vector<string> v;
int n, m;
int dist[1001][1001];
int d[1001][1001];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

#define rep(x, i,j) for(int x=i; x<j; x++)
#define pb push_back

int main()
{
    OJ;
    FIO;
    rep(i, 0,1001){
        rep(j, 0,1001){
            dist[i][j] = -1;
        }
    }

    cin >> n >> m;

    rep(i, 0, n){
        string x;
        cin >> x;
        v.pb(x);
    }

    int x, y, c1, c2;
    queue<vector<int>> q;    
    rep(i, 0, n){
        rep(j, 0, m){
            if(v[i][j] == 'M'){
                q.push({i, j, 0}); //ith index, jth index and steps
            }
            if(v[i][j] == 'A'){
                c1 = i;
                c2 = j;
            }
        }
    }

    x = c1;
    y = c2;

    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        int x = curr[0], y = curr[1], steps = curr[2];
        if(x<0 || x>=n || y<0 || y>=m || v[x][y] == '#' || dist[x][y]!=-1){
            continue;
        }

        dist[x][y] = steps;
        rep(i, 0, 4){
            int cx = x+dx[i], cy = y+dy[i];
            q.push({cx, cy, steps+1});
        }
    }


    string ans;
    while(!q.empty()){
        q.pop();
    }
    q.push({x, y, 0, 0});
     rep(i, 0,1001){
        rep(j, 0,1001){
            d[i][j] = -1;
        }
    }
    bool c = false;
    vector<vector<int>> p(n+1, vector<int>(m+1, 0));
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        int x = curr[0], y = curr[1], steps = curr[2], dir = curr[3];
        if(x<0 || x>=n || y<0 || y>=m || v[x][y] == '#' || d[x][y]!=-1 || (dist[x][y] >=0 && dist[x][y] <=steps)){
            continue;
        }

        if(x==n-1 || x == 0 || y == m-1 || y ==0){
            //Backtracking
            p[x][y] = dir;
            while(x!=c1 || y!=c2){
                if(p[x][y] == 0) ans+="L", y++;
                else if (p[x][y] == 1) ans+="R", y--;
                else if(p[x][y] == 2) ans+="U", x++;
                else ans+="D", x--;
            }

            c = true;
            break;
        }

        d[x][y] = steps;
        p[x][y] = dir;
        rep(i, 0, 4){
            int cx = x+dx[i], cy = y+dy[i];
            q.push({cx, cy, steps+1, i});
        }
    }

    if(c){
        cout << "YES" << endl;
        cout << ans.size() << endl;
        reverse(ans.begin(), ans.end());
        rep(i, 0, ans.size()){
            cout << ans[i];
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

}
