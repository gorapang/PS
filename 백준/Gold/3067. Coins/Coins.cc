#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dp[10001]; //dp[i]는 금액 i를 만드는 경우의 수
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		memset(dp, 0, sizeof(dp));
		int N;
		cin >> N;

		vector<int> coin(N, 0);
		for (int i = 0; i < N; i++)
			cin >> coin[i];

		int M;
		cin >> M;

		dp[0] = 1;
		for (int i = 0; i < N; i++)
		{
			for (int j = coin[i]; j <= M; j++)
			{
				dp[j] += dp[j - coin[i]];
			}
		}

		cout << dp[M] << '\n';
	}
	return 0;
}