#include <iostream>
#include <vector>
using namespace std;

int w, h;
vector<vector<int>> map;
vector<vector<bool>> visited;
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void dfs(int y, int x) 
{
    visited[y][x] = true;
    for (int i = 0; i < 8; i++) 
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= 0 && ny < h && nx >= 0 && nx < w) 
            if (map[ny][nx] == 1 && !visited[ny][nx]) 
                dfs(ny, nx);
            
        
    }
}

int main() 
{
    while (true) 
    {
        cin >> w >> h;
        if (w == 0 && h == 0) break;


        map.assign(h, vector<int>(w));
        visited.assign(h, vector<bool>(w, false));

        for (int i = 0; i < h; ++i) 
        {
            for (int j = 0; j < w; ++j) 
            {
                cin >> map[i][j];
            }
        }
        int count = 0;
        for (int i = 0; i < h; i++) 
        {
            for (int j = 0; j < w; j++) 
            {
                if (map[i][j] == 1 && !visited[i][j]) 
                {
                    dfs(i, j);
                    count++;
                }
            }
        }
        cout << count << '\n';
    }
    return 0;
}
