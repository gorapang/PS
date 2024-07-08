#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int arr[20][20];
bool visited[20];
int ans = 987654321;

void dfs(int cnt, int idx)
{
    if (cnt == n / 2)
    {
        int start = 0, link = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i] == true && visited[j] == true)
                    start += arr[i][j];
                if (visited[i] == false && visited[j] == false)
                    link += arr[i][j];
            }
        }

        ans = min(ans, abs(start - link));
        return;
    }

    for (int i = idx; i < n; i++)
    {
        visited[i] = true;
        dfs(cnt + 1, i + 1);
        visited[i] = false;
    }

}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    dfs(0, 0);
    cout << ans << '\n';
    return 0;
}
