#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;
vector<int> tmp;

int LIS()
{
    tmp.clear();
    for (int i = 0; i < n; i++)
    {
        if (tmp.empty() || tmp.back() < v[i])
            tmp.push_back(v[i]);
        else
        {
            int index = lower_bound(tmp.begin(), tmp.end(), v[i]) - tmp.begin();
            tmp[index] = v[i];
        }
    }
    return tmp.size();
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    cout << n - LIS() << '\n';

    return 0;
}
