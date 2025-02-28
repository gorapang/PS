#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;


int main() 
{
	int n;
	cin >> n;

	int dp[11];
	dp[1] = 0;
	dp[2] = 1;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + i - 1;
	}
	cout << dp[n] << '\n';
}
