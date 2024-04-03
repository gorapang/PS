#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define INF 987654321
using namespace std;

int dp[100]; //dp[i]: i번째 위치에서의 최대 전기줄 개수
int res;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;

	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first >> v[i].second;
	}


	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
			if (v[j].second < v[i].second)
				dp[i] = max(dp[i], dp[j] + 1);

		res = max(res, dp[i]);
	}

	cout << n - res << '\n';

	return 0;
}
