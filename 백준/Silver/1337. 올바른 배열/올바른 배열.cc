#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int maxlen = 1, curlen = 1;

    int s = 0, e = 0;
    while (e < n) {
        if (v[e] - v[s] < 5)
        {
            e++;
            maxlen = max(maxlen, e - s);
        }
        else
        {
            s++;
        }
    }

    cout << max(5 - maxlen, 0) << '\n';
    return 0;
}
