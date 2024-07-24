#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, k, m;
vector<int> v;

bool check(int p) 
{
    int count = 0;
    for (int length : v) 
    {
        int cut_length;
        if (length >= 2 * k) 
        {
            cut_length = length - 2 * k;
        }

        else if (length >= k) 
        {
            cut_length = length - k;
        }
        else continue;
        

        count += cut_length / p;

        if (count >= m) 
            return true;
    }

    return false;
}

int solve(int max_val) 
{
    int low = 1, high = max_val;
    int best = -1;

    while (low <= high) 
    {
        int mid = low + (high - low) / 2;

        if (check(mid)) 
        {
            best = mid;
            low = mid + 1;
        }
        else 
        {
            high = mid - 1;
        }
    }

    return best;
}


int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k >> m;
    v.resize(n);

    int max_val = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        max_val = max(max_val, v[i]);
    }
        
    
    cout << solve(max_val) << '\n';

    return 0;
}
