#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string a, b;
    cin >> a >> b;

    int aLen = a.length();
    int bLen = b.length();
    vector<vector<int>> dp(bLen, vector<int>(aLen, 0));

    int ans = 0;

    for (int i = 0; i < bLen; i++)
    {
        for (int j = 0; j < aLen; j++)
        {
            if (a[j] == b[i])
            {
                dp[i][j] = 1;
                if (i >= 1 && j >= 1) dp[i][j] += dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
