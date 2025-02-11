#include <iostream>
#include <string>
using namespace std;

int solve(string& s, string& p) 
{
    int slen = s.size();
    int plen = p.size();
    int time = 0;

    for (int i = 0; i < slen; ) 
    {
        if (s.substr(i, plen) == p) 
        {
            time++; 
            i += plen;  
        }
        else 
        {
            time++;  
            i++;
        }
    }

    return time;
}

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    while (T--) 
    {
        string s, p;
        cin >> s >> p;
        cout << solve(s, p) << '\n';
    }
    return 0;
}
