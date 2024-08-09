#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    stack<int> s;
    string res; 
    int cur = 1;

    for (int i = 0; i < n; i++)
    {
        int num = v[i];

        while (cur <= num)
        {
            s.push(cur);
            res += '+';
            res += '\n'; 
            cur++;
        }

        if (s.top() == num)
        {
            s.pop();
            res += '-';
            res += '\n';
        }
        else
        {
            cout << "NO\n";
            return 0;
        }
    }

    cout << res; 
    return 0;
}
