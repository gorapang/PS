#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int arr[1001];
    vector<int> v;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        if (v.empty()) v.push_back(arr[i]);
        else
        {
            if (v.back() > arr[i])
            {
                int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
                v[idx] = arr[i];
            }

            else if (v.back() < arr[i])
                v.push_back(arr[i]);
        }
    }

    cout << v.size() << '\n';
    return 0;
}
