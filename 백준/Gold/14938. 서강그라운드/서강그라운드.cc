#include <iostream>
#include <vector>
#include <algorithm> 
#define INF 987654321
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m, r;
    cin >> n >> m >> r;

    int dist[101][101];
    int item[101];

    for (int i = 1; i <= n; i++)
        cin >> item[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dist[i][j] = (i == j) ? 0 : INF;

    for (int i = 0; i < r; i++)
    {
        int a, b, l;
        cin >> a >> b >> l;
        dist[a][b] = l;
        dist[b][a] = l;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    int cnt; int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt = item[i];
        for (int j = 1; j <= n; j++)
        {
            if (i == j) continue;
            if (dist[i][j] <= m) cnt += item[j];
        }
        ans = max(ans, cnt);
    }

    cout << ans << '\n';

    return 0;
}
