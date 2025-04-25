#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> L(n), J(n);
    for (int i = 0; i < n; i++) cin >> L[i];
    for (int i = 0; i < n; i++) cin >> J[i];

    vector<int> dp(100, 0); 

    for (int i = 0; i < n; i++)
    {
        for (int h = 99; h >= L[i]; h--)
        {
            dp[h] = max(dp[h], dp[h - L[i]] + J[i]);
        }
    }

    int ans = 0;
    for (int h = 1; h < 100; h++)
    {
        ans = max(ans, dp[h]);
    }

    cout << ans << '\n';
    return 0;
}
