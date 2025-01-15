#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string str;
    cin >> str;

    map<char, int> freq;
    for (char c : str) 
    {
        freq[c]++;
    }

    int odd_char_cnt = 0;
    char odd_char = 0;
    for (auto a : freq) 
    {
        if (a.second % 2 != 0) 
        {
            odd_char_cnt++;
            odd_char = a.first;
        }
    }

    if (odd_char_cnt > 1) 
    {
        cout << "I'm Sorry Hansoo" << '\n';
        return 0;
    }

    string half = "";
    for (auto& a : freq) 
    {
        half += string(a.second / 2, a.first);
    }

    sort(half.begin(), half.end());
    string res = half;
    if (odd_char_cnt == 1) 
    {
        res += odd_char;
    }
    reverse(half.begin(), half.end());
    res += half;

    cout << res << '\n';;
    return 0;
}
