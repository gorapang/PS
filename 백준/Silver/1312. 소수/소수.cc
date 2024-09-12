#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b, n;
    cin >> a >> b >> n;

    a = a % b; 
    for (int i = 0; i < n - 1; i++) 
    {
        a *= 10;     
        a = a % b;   
    }

    a *= 10;
    cout << a / b << '\n';

    return 0;
}