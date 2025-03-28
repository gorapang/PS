#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int M, N, K;
int grid[101][101]; 
bool visited[101][101]; 
vector<int> sizes; 
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs(int x, int y) 
{
    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = true;
    int size = 1;

    while (!q.empty()) 
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) 
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[nx][ny] && grid[nx][ny] == 0) 
            {
                visited[nx][ny] = true;
                q.push({ nx, ny });
                size++;
            }
        }
    }

    sizes.push_back(size);
}

int main() 
{
    cin >> M >> N >> K;
    vector<pair<int, int>> v(K);

    for (int i = 0; i < K; i++) 
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int x = x1; x < x2; x++) 
            for (int y = y1; y < y2; y++) 
                grid[y][x] = 1; 
            
        
    }


    for (int i = 0; i < M; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            if (!visited[i][j] && grid[i][j] == 0) 
            {
                bfs(i, j);
            }
        }
    }


    sort(sizes.begin(), sizes.end());

    cout << sizes.size() << '\n';
    for (int i = 0; i < sizes.size(); i++)
    {
        cout << sizes[i] << " ";
    }

    
    cout << '\n';

    return 0;
}
