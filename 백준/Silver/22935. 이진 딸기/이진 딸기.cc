#include <iostream>
using namespace std;

string to_str(int n)
{
    string s = "";
    for (int i = 3; i >= 0; --i)
    {
        if (n & (1 << i))
            s += "딸기";
        else
            s += "V";
    }
    return s;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;

        int i = (n - 1) % 28;
        int num;
        if (i < 15)
            num = i + 1;
        else
            num = 14 - (i - 15);

        cout << to_str(num) << '\n';
    }
    return 0;
}
