#include <iostream>
using namespace std;

int solve(int n) 
{
    for (int i = n / 5; i >= 0; i--) 
    { 
        int left = n - (i * 5);
        if (left % 2 == 0) 
        { 
            return i + (left / 2); 
        }
    }
    return -1; 
}

int main() 
{
    int n;
    cin >> n;
    cout << solve(n) << '\n';
    return 0;
}
