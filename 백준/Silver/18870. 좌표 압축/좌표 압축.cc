#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    vector<int> cp(n);
    for (int i = 0; i < n; i++)
        cp[i] = v[i];

    sort(cp.begin(), cp.end()); 
    cp.erase(unique(cp.begin(), cp.end()), cp.end());


    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(cp.begin(), cp.end(), v[i]);
        cout << it - cp.begin() << ' ';
    }

    return 0;
}