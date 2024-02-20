#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <math.h>
#include <list>
using namespace std;

int h, w, n;
int map[1001][1001];
int dp[1001][1001];

void dfs(int x, int y)
{
	if (x > h || y > w)
	{
		cout << x << ' ' << y << '\n';
		return;
	}
	if (dp[x][y] == 0) dfs(x + 1, y);
	else dfs(x, y + 1);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> h >> w >> n;
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			cin >> map[i][j];
		}
	}

	dp[1][1] = n - 1;
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			if (dp[i][j] == 0) continue;

			dp[i + 1][j] += dp[i][j] / 2;
			dp[i][j + 1] += dp[i][j] / 2;

			if (dp[i][j] % 2 == 1) //dp[i][j]가 짝수 
			{
				if (map[i][j] == 0) //아래
					dp[i + 1][j]++;
				else if (map[i][j] == 1) //오른쪽
					dp[i][j + 1]++;
			}
		}
	}

	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			dp[i][j] = (map[i][j] + dp[i][j]) % 2;
		}
	}


	//탐색
	dfs(1, 1);

	return 0;
}