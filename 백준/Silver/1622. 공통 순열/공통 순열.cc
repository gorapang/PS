#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() 
{
    string a, b;
    while (getline(cin, a) && getline(cin, b)) 
    {
        vector<int> freqA(26, 0), freqB(26, 0);

        for (char c : a) 
            freqA[c - 'a']++;
        for (char c : b) 
            freqB[c - 'a']++;

        string res;

        for (int i = 0; i < 26; ++i) 
        {
            int cnt = min(freqA[i], freqB[i]);
            res += string(cnt, i + 'a');
        }

        sort(res.begin(), res.end());
        cout << res << '\n';
    }

    return 0;
}
