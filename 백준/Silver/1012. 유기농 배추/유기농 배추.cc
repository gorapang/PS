#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int t, n, m, k;

int arr[51][51];
int visited[51][51];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void dfs(int y, int x)
{
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (ny < 0 || nx < 0 || nx >= m || ny >= n) continue;

		if (arr[ny][nx] && !visited[ny][nx])
			dfs(ny, nx);
	}
}

int main()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> m >> n >> k;

		memset(arr, 0, sizeof(arr));
		memset(visited, 0, sizeof(visited));

		for (int j = 0; j < k; j++)
		{
			int x, y;
			cin >> x >> y;
			arr[y][x] = 1;
		}

		int cnt = 0;
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
			{
				if (arr[j][k] && !visited[j][k])
				{
					dfs(j, k);
					cnt++;
				}
			}

		cout << cnt << '\n';
	}
	return 0;
}