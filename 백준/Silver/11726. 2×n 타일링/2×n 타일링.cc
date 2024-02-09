#include <iostream>
using namespace std;

int N;
int dp[1001]; // dp[i]는 2xi 크기의 직사각형을 채우는 방법의 수

int main()
{
	cin >> N;
	dp[1] = 1; dp[2] = 2; 
	for (int i = 3; i <= N; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}
	cout << dp[N] << '\n';
	return 0;
}