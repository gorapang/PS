#include <iostream>
#include <vector>
using namespace std;


void solve(int n) 
{
    for (int i = 2; i * i <= n; ++i) 
    {
        int cnt = 0;
        while (n % i == 0) 
        {
            n /= i;
            cnt++;
        }

        if (cnt > 0) 
        {
            cout << i << " " << cnt << '\n';
        }
    }
    
    if (n > 1) 
    { 
        cout << n << " 1" << '\n';
    }
}

int main() 
{
    int T; 
    cin >> T;

    while (T--) 
    {
        int N;
        cin >> N;
        solve(N);
    }

    return 0;
}
