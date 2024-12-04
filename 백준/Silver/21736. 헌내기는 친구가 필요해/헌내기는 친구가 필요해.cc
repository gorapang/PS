#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M; 
vector<string> v; 
vector<vector<bool>> visited; 
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int bfs(int startx, int starty) 
{
    queue<pair<int, int>> q;
    q.push({ startx, starty });
    visited[startx][starty] = true;

    int cnt = 0;

    while (!q.empty()) 
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (v[x][y] == 'P') 
            cnt++;
        
        for (int i = 0; i < 4; i++) 
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny] && v[nx][ny] != 'X') 
            {
                visited[nx][ny] = true;
                q.push({ nx, ny });
            }
        }
    }

    return cnt;
}

int main() 
{
    cin >> N >> M;
    v.resize(N);
    visited.resize(N, vector<bool>(M, false));

    int x, y;

    for (int i = 0; i < N; i++) 
    {
        cin >> v[i];
        for (int j = 0; j < M; j++) 
        {
            if (v[i][j] == 'I') 
            { 
                x = i;
                y = j;
            }
        }
    }

    int result = bfs(x, y);

    if (result == 0)
        cout << "TT\n";
    else
        cout << result << '\n';
    

    return 0;
}
