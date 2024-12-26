#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) 
{
    if (a == 0) return b;
    return gcd(b % a, a);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        long long sum = 0;

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                sum += gcd(arr[i], arr[j]);  

        cout << sum << '\n';
    }

    return 0;
}
