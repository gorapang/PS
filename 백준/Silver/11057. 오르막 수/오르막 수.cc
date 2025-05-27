#include <iostream>
using namespace std;

const int MOD = 10007;

int main()
{
    int N;
    cin >> N;

    int dp[1001][10] = { 0 };

    for (int i = 0; i < 10; ++i)
        dp[1][i] = 1;

    for (int i = 2; i <= N; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            for (int k = 0; k <= j; ++k)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < 10; ++i)
    {
        answer = (answer + dp[N][i]) % MOD;
    }

    cout << answer << '\n';
    return 0;
}
