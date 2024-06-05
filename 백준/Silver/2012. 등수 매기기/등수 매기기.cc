#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    long long ans = 0;
    for (int i = 0; i < n; i++)
        ans += abs(v[i] - i - 1);

    cout << ans << '\n';

    return 0;
}