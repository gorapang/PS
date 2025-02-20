#include <iostream>
#include <queue>

using namespace std;

int arr[1000][1000];
int dist[1000][1000]; 
int dx[] = { 0, 0, 1, -1 }; 
int dy[] = { 1, -1, 0, 0 };
int n, m;

void bfs(int sx, int sy)
{
    queue<pair<int, int>> q;
    q.push({ sx, sy });
    dist[sx][sy] = 0; 

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (arr[nx][ny] == 0) continue; 
            if (dist[nx][ny] != -1) continue; 

            dist[nx][ny] = dist[x][y] + 1;
            q.push({ nx, ny });
        }
    }
}

int main()
{
    int sx = -1, sy = -1;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            dist[i][j] = -1; 
            if (arr[i][j] == 2)
            {
                sx = i;
                sy = j;
            }
        }
    }

    bfs(sx, sy); 

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0) cout << 0 << ' ';
            else if (dist[i][j] == -1) cout << -1 << ' ';
            else cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
