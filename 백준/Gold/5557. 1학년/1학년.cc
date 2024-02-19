#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <math.h>
#include <list>
using namespace std;

int n;
long long dp[101][21]; // dp[i][j]는 i번째 수까지 사용해 j를 만드는 경우의 수

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    dp[0][v[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int val = 0; val < 21; val++)
        {
            if (dp[i - 1][val] != 0)
            {
                if (val + v[i] <= 20) dp[i][val+v[i]] += dp[i - 1][val];
                if (val - v[i] >= 0) dp[i][val-v[i]] += dp[i - 1][val];
            }
        }
    }

    cout << dp[n - 2][v[n-1]] << '\n';


    return 0;
}