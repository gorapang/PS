#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int l, n, t;
    cin >> l >> n >> t;
    vector<pair<int, char>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    int ans = 0;  

    while (t--)
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i].second == 'R')
            {
                if (v[i].first == l)
                {
                    v[i].second = 'L';
                    v[i].first--;
                }
                else
                {
                    v[i].first++;
                }
            }
            else
            {
                if (v[i].first == 0)
                {
                    v[i].second = 'R';
                    v[i].first++;
                }
                else
                {
                    v[i].first--;
                }
            }
        }

        sort(v.begin(), v.end());

        for (int i = 0; i < n - 1; i++)
        {
            if (v[i].first == v[i + 1].first)
            {
                ans++; 
                v[i].second = (v[i].second == 'R') ? 'L' : 'R';
                v[i + 1].second = (v[i + 1].second == 'R') ? 'L' : 'R';
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
