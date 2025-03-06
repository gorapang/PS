#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string word, res;
    cin >> word;

    int len = word.length();
    res = "~";

    for (int i = 1; i < len - 1; i++) 
    {
        for (int j = i + 1; j < len; j++) 
        {
            string part1 = word.substr(0, i);
            reverse(part1.begin(), part1.end());

            string part2 = word.substr(i, j - i);
            reverse(part2.begin(), part2.end());

            string part3 = word.substr(j);
            reverse(part3.begin(), part3.end());

            string new_word = part1 + part2 + part3;

            if (new_word < res) 
            {
                res = new_word;
            }
        }
    }

    cout << res << '\n';
    return 0;
}
