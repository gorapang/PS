#include <iostream>
#include <vector>
using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
bool visited[30][30];
double prob[4];
double ans = 0.0;

void dfs(int x, int y, int cnt, int maxcnt, double p) 
{
    if (cnt == maxcnt) 
    {
        ans += p;
        return;
    }

    for (int i = 0; i < 4; i++) 
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (visited[nx][ny]) continue;

        visited[nx][ny] = true;
        dfs(nx, ny, cnt + 1, maxcnt, p * prob[i]);
        visited[nx][ny] = false;
    }
}

int main() 
{
    int N;
    cin >> N;

    int e, w, s, n;
    cin >> e >> w >> s >> n;

    prob[0] = e / 100.0;
    prob[1] = w / 100.0;
    prob[2] = s / 100.0;
    prob[3] = n / 100.0;

    int sx = 15, sy = 15;
    visited[sx][sy] = true;
    dfs(sx, sy, 0, N, 1.0);

    cout.precision(10);
    cout << fixed << ans << '\n';
    return 0;
}
