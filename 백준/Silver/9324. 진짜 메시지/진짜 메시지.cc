#include <iostream>
#include <string>
using namespace std;

bool is_real(string& msg) 
{
    int cnt[26] = { 0 }; 

    for (int i = 0; i < msg.size(); i++) 
    {
        char c = msg[i];
        cnt[c - 'A']++;

        if (cnt[c - 'A'] % 3 == 0) 
        { 
            if (i + 1 >= msg.size() || msg[i + 1] != c) 
                return false; 
            
            i++; 
        }
    }
    return true;
}

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T--) 
    {
        string msg;
        cin >> msg;
        if (is_real(msg)) 
        {
            cout << "OK" << '\n';
        }
        else 
        {
            cout << "FAKE" << '\n';
        }
    }
    return 0;
}
