#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
char arr[3001][3001];
bool visited[3001][3001];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int bfs(int startx, int starty)
{
    queue<pair<int, int>> q;
    q.push({ startx,starty });
    visited[startx][starty] = true;

    int qsize;
    int depth = 0;

    while (!q.empty())
    {
        qsize = q.size();
        for (int i = 0; i < qsize; i++)
        {
            auto p = q.front();
            int x = p.first;
            int y = p.second;
            q.pop();

            if (arr[x][y] == '3' || arr[x][y] == '4' || arr[x][y] == '5')
                return depth;

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (visited[nx][ny]) continue;
                if (arr[nx][ny] == '1') continue;
                     
                visited[nx][ny] = true;
                q.push({ nx, ny });
            }

        }

        depth++;
    }
    return -1;
}

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int startx, starty;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == '2')
            {
                startx = i; starty = j;
            }
        }
    }

    int min_dist = bfs(startx, starty);

    if (min_dist == -1)
        cout << "NIE\n";
    else
    {
        cout << "TAK\n";
        cout << min_dist << '\n';
    }
    return 0;
}
