#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    vector<int> v(n+1);
    vector<int> sum(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        sum[i] = sum[i - 1] + v[i];
    }
    

    long long ans = 0;
    for (int i = 1; i < n; i++)
    {
        ans += (sum[n] - sum[i]) * v[i];
    }   
    cout << ans << '\n';
    return 0;
}
