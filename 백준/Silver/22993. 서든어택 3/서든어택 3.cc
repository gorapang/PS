#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; 
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) 
        cin >> v[i];
    
    long long junwon = v[0];

    vector<int> other(v.begin() + 1, v.end());
    sort(other.begin(), other.end());

    bool flag = true;
    for (auto a : other) 
    {
        if (junwon > a)
        {
            junwon += a;
        }
        else 
        {
            flag = false;
            break;
        }
    }

    cout << (flag ? "Yes" : "No") << '\n';

    return 0;
}