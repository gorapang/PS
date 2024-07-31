#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int before[30][30];
int after[30][30];
bool visited[30][30];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };


void dfs(int x, int y, int beforeval, int afterval)
{
    before[x][y] = afterval;
    visited[x][y] = true;

    for (int i = 0; i < 4; ++i) 
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) continue;
        if (before[nx][ny] != beforeval) continue;

        dfs(nx, ny, beforeval, afterval);
    }
}

bool check()
{
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            if (before[i][j] != after[i][j])
                return false;

    return true;
}

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j)
            cin >> before[i][j];

    for (int
        i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) 
            cin >> after[i][j];


    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            if (before[i][j] != after[i][j]) 
            {
                dfs(i, j, before[i][j], after[i][j]);

                if (!check())
                {
                    cout << "NO" << '\n';
                    return 0;
                }
                
            }
        }
    }

    cout << "YES" << '\n';
    return 0;
}
