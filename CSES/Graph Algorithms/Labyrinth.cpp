#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

#define ll long long int

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define pii pair<int, int>

char arr[1001][1001];
int n, m, sx, sy, ex, ey;

vector<vector<pair<int, int>>> path;
vector<vector<bool>> vis;

vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool isValid(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
    {
        return false;
    }

    if (vis[x][y])
    {
        return false;
    }

    return true;
}

void bfs()
{
    queue<pair<int, int>> q;
    q.push({sx, sy});
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (auto mv : moves)
        {
            int mvx = mv.first;
            int mvy = mv.second;
            if (isValid(cx + mvx, cy + mvy))
            {
                q.push({cx + mvx, cy + mvy});
                vis[cx+mvx][cy+mvy] = true;
                path[cx + mvx][cy + mvy] = {mvx, mvy};
            }
        }
    }
}

int main()
{
    OJ;
    cin >> n >> m;
    path.resize(n);
    vis.resize(n);
    for (int i = 0; i < n; ++i)
    {
        path[i].resize(m);
        vis[i].resize(m);
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            path[i][j] = {-1, -1};
            char c;
            cin >> c;
            if (c == '#')
            {
                vis[i][j] = true;
            }
            if (c == 'A')
            {
                sx = i;
                sy = j;
            }
            if (c == 'B')
            {
                ex = i;
                ey = j;
            }
        }
    }

    bfs();

    if (vis[ex][ey] == false)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        vector<pair<int, int>> ans;
        pair<int, int> end = {ex, ey};
        while(end.first!=sx || end.second!=sy){
            ans.push_back(path[end.first][end.second]);
            end.first = end.first-ans.back().first;
            end.second = end.second - ans.back().second;
        }

        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for(auto a: ans){
            if(a.first == 1 && a.second == 0){
                cout << 'D';
            }
            if(a.first == -1 && a.second == 0){
                cout << 'U';
            }
            if(a.first == 0 && a.second == 1){
                cout << 'R';
            }
            if(a.first == 0 && a.second == -1){
                cout << 'L';
            }
        }

    }
}
