#include <iostream>
using namespace std;

int main() 
{
    int n;
    cin >> n;

    if (n < 4) 
    {
        cout << 0 << '\n';
    }
    else 
    {
        int ans = (n * (n - 1) * (n - 2) * (n - 3)) / 24;
        cout << ans << '\n';
    }

    return 0;
}
