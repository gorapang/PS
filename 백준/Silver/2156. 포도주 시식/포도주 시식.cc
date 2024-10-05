#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    vector<int> dp(n+1); //dp[i]: i번째 잔까지 최대 양

    dp[0] = 0;
    dp[1] = v[1];
    dp[2] = v[1] + v[2];

    for (int i = 3; i <= n; i++)
    {
        dp[i] = max(max(dp[i - 2] + v[i], dp[i - 3] + v[i - 1] + v[i]), dp[i-1]);
    }
    
    cout << dp[n] << '\n';

    /*
    OOXO
    OXOO
    XOOX
    */
    return 0;
}
