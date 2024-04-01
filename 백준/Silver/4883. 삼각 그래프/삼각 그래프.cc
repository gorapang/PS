#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define INF 987654321
using namespace std;

int tc = 1;
int arr[100001][3];
int dp[100001][3];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	while (1)
	{
		int n;
		cin >> n;
		if (n == 0) break;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < 3; j++)
				cin >> arr[i][j];

		dp[0][0] = INF;
		dp[0][1] = arr[0][1];
		dp[0][2] = arr[0][1] + arr[0][2];

		//for (int i = 0; i < 3; i++)
		//{
		//	dp[1][i] = arr[0][1] + arr[1][i];
		//}

		for (int i = 1; i < n; i++)
		{
			dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][0];
			dp[i][1] = min(min(min(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]), dp[i][0]) + arr[i][1];
			dp[i][2] = min(min(dp[i - 1][1], dp[i - 1][2]), dp[i][1]) + arr[i][2];
		}

		cout << tc << ". " << dp[n - 1][1] << '\n';
		tc++;
	}

	return 0;
}
