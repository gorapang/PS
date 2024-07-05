#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<pair<int,int>> v(n); //제한시간 s, 소요시간 t
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].second >> v[i].first;
    }

    sort(v.begin(), v.end(), greater<pair<int,int>>());

    int ans = v[0].first;


    for (int i = 0; i < n; i++)
    {
        int s = v[i].first;
        int t = v[i].second;
        if (ans > s) {
            ans = s;
        }
        ans -= t;
    }

    if (ans < 0) ans = -1;
    cout << ans << '\n';

    return 0;
}
