#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;

        vector<vector<int>> v(3, vector<int>(n+1));
        for (int i = 1; i <= 2; i++)
            for (int j = 1; j <= n; j++)
                cin >> v[i][j];

        vector<vector<int>> dp(3, vector<int>(n+1, 0)); // dp[i][j]: v[i][j]를 선택했을 때 최대 점수
        dp[1][0] = 0;
        dp[2][0] = 0;

        if (n == 1) {
            cout << max(v[1][1], v[2][1]) << '\n';  // n이 1일 때는 첫 번째 줄과 두 번째 줄 중 최대값 출력
            continue;
        }

        dp[1][1] = v[1][1];
        dp[2][1] = v[2][1];

        dp[1][2] = v[2][1] + v[1][2];
        dp[2][2] = v[1][1] + v[2][2];

        for (int i = 3; i <= n; i++)
        {
            // 윗줄
            dp[1][i] = max(dp[2][i - 1] + v[1][i], dp[2][i - 2] + v[1][i]);

            // 아랫줄
            dp[2][i] = max(dp[1][i - 1] + v[2][i], dp[1][i - 2] + v[2][i]);
        }
        
        cout << max(dp[1][n], dp[2][n]) << '\n';  // 최종 결과 출력
    }
    return 0;
}
