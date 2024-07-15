#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> v[i][j];

    vector<vector<int>> dp(n, vector<int>(m));

    dp[0][0] = v[0][0];
    for (int i = 1; i < m; i++)
        dp[0][i] = v[0][i] + dp[0][i - 1];
    
    for (int i = 1; i < n; i++)
        dp[i][0] = v[i][0] + dp[i - 1][0];


    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            dp[i][j] = max(max(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1]) + v[i][j];
        }
    }

    cout << dp[n - 1][m - 1] << '\n';
    return 0;
}
