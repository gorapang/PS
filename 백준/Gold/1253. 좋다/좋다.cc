#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<long> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int l = 0, r = n - 1;
        while (l < r) {
            if (l == i) {
                l++;
                continue;
            }
               
            if (r == i) {
                r--; continue;
            }

            if (v[i] > v[l] + v[r]) l++;
            else if (v[i] == v[l] + v[r]) {
                ans++; break;
            }
            else r--;
        }
    }

    cout << ans << '\n';

    return 0;
}
