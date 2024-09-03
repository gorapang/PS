#include <iostream>
#include <vector>

using namespace std;


long long solve(int n, int k) {
    long long result = 1;

    if (k > n - k)
        k = n - k;
    for (int i = 0; i < k; ++i) 
    {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;

    vector<long long> dp(65, 0);


    for (int n = 0; n < 65; n++) 
    {
        dp[n] = solve(n + 9, 9);
    }

    while (T--) 
    {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}
