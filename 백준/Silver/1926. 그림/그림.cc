#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int paper[500][500];
bool visited[500][500];
int dx[4] = { 1, -1, 0, 0 };  
int dy[4] = { 0, 0, 1, -1 };

int bfs(int x, int y) 
{
    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = true;
    int area = 1;

    while (!q.empty()) 
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) 
        {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) 
            {
                if (!visited[nx][ny] && paper[nx][ny] == 1) 
                {
                    visited[nx][ny] = true;
                    q.push({ nx, ny });
                    area++;
                }
            }
        }
    }

    return area;
}

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> paper[i][j];

    int count = 0;
    int max_area = 0;

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if (!visited[i][j] && paper[i][j] == 1) 
            {
                count++;
                max_area = max(max_area, bfs(i, j));
            }
        }
    }

    cout << count << '\n' << max_area << '\n';
    return 0;
}
