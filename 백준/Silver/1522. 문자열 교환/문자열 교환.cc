#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int solve(string& s) 
{
    int n = s.size();
    int a_cnt = count(s.begin(), s.end(), 'a');

    if (a_cnt == 0 || a_cnt == n) 
        return 0;

    string ss = s + s; 
    int b_cnt = 0, ans;

    for (int i = 0; i < a_cnt; i++) 
    {
        if (ss[i] == 'b') b_cnt++;
    }
    ans = b_cnt;

    for (int i = 1; i < n; i++) 
    {
        if (ss[i - 1] == 'b') b_cnt--;
        if (ss[i + a_cnt - 1] == 'b') b_cnt++;

        ans = min(ans, b_cnt);
    }

    return ans;
}

int main() 
{
    string s;
    cin >> s;
    cout << solve(s) << '\n';
    return 0;
}
