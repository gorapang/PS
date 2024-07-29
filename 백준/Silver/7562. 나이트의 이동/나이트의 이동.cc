#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int t, I;
int x, y, target_x, target_y;
int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[] = { 2, 1, -1, -2, -2, -1, 1, 2 };

void bfs(int x, int y, int target_x, int target_y) 
{
    int visited[301][301];
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;

    q.push({ x, y });
    visited[x][y] = 1;

    while (!q.empty()) 
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        if (a == target_x && b == target_y) {
            cout << visited[a][b] - 1 << "\n";
            return;
        }

        for (int i = 0; i < 8; i++) {
            int na = a + dx[i];
            int nb = b + dy[i];

            if (na >= 0 && nb >= 0 && na < I && nb < I && !visited[na][nb]) {
                q.push({ na, nb });
                visited[na][nb] = visited[a][b] + 1;
            }
        }
    }
}

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) 
    {
        cin >> I; 
        cin >> x >> y >> target_x >> target_y;

        bfs(x, y, target_x, target_y);
    }

    return 0;
}
