#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m;
char arr[100][100];
bool visited[100][100];

int bfs(int x, int y, char color)
{
    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = true;
    int cnt = 1;

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny] || arr[nx][ny] != color)
                continue;

            visited[nx][ny] = true;
            q.push({ nx, ny });
            cnt++;
        }
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;  

    for (int i = 0; i < m; i++)  
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    int W_cnt = 0, B_cnt = 0;
    for (int i = 0; i < m; i++)  
    {
        for (int j = 0; j < n; j++) 
        {
            if (!visited[i][j])
            {
                char color = arr[i][j];
                int cnt = bfs(i, j, color);
                if (color == 'W')
                    W_cnt += cnt * cnt;
                else B_cnt += cnt * cnt;
            }
        }
    }

    cout << W_cnt << ' ' << B_cnt << '\n';

    return 0;
}
