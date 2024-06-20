#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> dp(n+1);
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 0;
    for (int i = 4; i <= n; i++)
    {
        if (dp[i - 1] == 0 || dp[i - 3] == 0)
            dp[i] = 1;
        else dp[i] = 0;
    }

    if (dp[n] == 1) cout << "SK\n";
    else cout << "CY\n";
    return 0;
}