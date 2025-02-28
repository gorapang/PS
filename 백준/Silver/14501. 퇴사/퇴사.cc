#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;


int main() 
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	vector<int> p(n + 1);
	vector<int> t(n + 1);
	vector<int> dp(n + 2,0);
	for (int i = 1; i <= n; i++)
		cin >> t[i] >> p[i];

	for (int i = n; i >= 1; i--)
	{
		if (i + t[i] > n + 1)//불가
			dp[i] = dp[i + 1];
		else
		{
			dp[i] = max(dp[i + 1], p[i] + dp[i + t[i]]);
		}
	}

	cout << dp[1] << '\n';

	return 0;
}
