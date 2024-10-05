#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[50][50];
int visited[50][50];  // 방문 여부와 depth를 함께 관리
int n, m;
int max_dist;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int sum;

void init()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            visited[i][j] = 0;
}

void bfs(int x, int y)
{
    int sx = x, sy = y;
    queue<pair<int, int>> q;
    q.push({ x, y });

    init();
    visited[x][y] = 1;  // 시작점을 방문처리하면서 depth 1로 설정

    int depth = 0;

    while (!q.empty())
    {
        int qsize = q.size();
        for (int i = 0; i < qsize; i++)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            // 최장 거리(depth)를 갱신할 때마다 sum 계산
            if (depth > max_dist) {
                max_dist = depth;
                sum = arr[sx][sy] + arr[x][y];  // 현재까지의 최대 거리에서의 합
            }
            else if (depth == max_dist) {
                sum = max(sum, arr[sx][sy] + arr[x][y]);
            }

            // 4방향 탐색
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx >= n || nx < 0 || ny >= m || ny < 0 || visited[nx][ny] || arr[nx][ny] == 0)
                    continue;

                visited[nx][ny] = 1;  // 새로운 위치를 방문 처리
                q.push({ nx, ny });
            }
        }
        depth++;  // 모든 현재 큐에 있는 노드를 처리한 후 깊이를 1 증가
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    sum = 0;
    max_dist = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (arr[i][j] != 0)
            {
                bfs(i, j);
            }

    cout << sum << '\n';

    return 0;
}
