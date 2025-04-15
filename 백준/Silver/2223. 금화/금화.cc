#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t, x, m;
    cin >> t >> x >> m;

    int min_safe = t;  
    for (int i = 0; i < m; ++i)
    {
        int d, s;
        cin >> d >> s;
        int safe_time = (d - 1) / s;
        min_safe = min(min_safe, safe_time);
    }

    int ans = 0;

    if (m == 0)
    {
        ans = x * t;
    }
    else if (min_safe == 0)
    {
        ans = 0;
    }
    else if (t <= min_safe)
    {
        ans = x * t;
    }
    else
    {
        int extra = (t - min_safe) / 2;
        ans = x * (min_safe + extra);
    }

    cout << ans << '\n';
    return 0;
}
