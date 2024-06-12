#include <iostream>
#include <vector>
#include <algorithm> 
#define INF 987654321
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> b(m);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int ans = 0;
        int p = 0;
        for (int i = 0; i < n; i++)
        {
            while (p <m && a[i] > b[p])
                p++;
            ans += p;
        }
        cout << ans << '\n';

    }

    return 0;
}
