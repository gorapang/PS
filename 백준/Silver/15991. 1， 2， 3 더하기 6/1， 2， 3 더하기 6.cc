#include <iostream>

using namespace std;

long long mod = 1000000009;
long long dp[100001];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 2;
    dp[4] = 3;
    dp[5] = 3;
    dp[6] = 6;
    for (int i = 7; i <= 100000; i++)
    {
        dp[i] = dp[i - 2] % mod + dp[i - 4] % mod + dp[i - 6] % mod;
        dp[i] %= mod;
    }

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}
