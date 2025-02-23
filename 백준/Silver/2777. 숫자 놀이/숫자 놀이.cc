#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(long long n) 
{
    if (n == 1) return 1; 

    vector<int> v;

    for (int d = 9; d >= 2; d--) 
    {
        while (n % d == 0) 
        {
            v.push_back(d);
            n /= d;
        }
    }

    if (n != 1) return -1;
    sort(v.begin(), v.end());
    return v.size();
}

int main() 
{
    int T;
    cin >> T;

    while (T--) 
    {
        long long n;
        cin >> n;
        cout << solve(n) << '\n';
    }

    return 0;
}
