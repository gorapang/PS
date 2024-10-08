#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    int ans = 0;

    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end()); 

    for (int i = 0; i < n; i++)
        ans += v[i] * (n - i);

    cout << ans << '\n';

    return 0;
}