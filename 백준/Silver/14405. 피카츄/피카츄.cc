#include <iostream>
#include <string>
using namespace std;

bool check(string S) 
{
    size_t pos = 0;

    while (pos < S.size())
    {
        if (S.substr(pos, 2) == "pi")
        {
            pos += 2;
        }
        else if (S.substr(pos, 2) == "ka")
        {
            pos += 2;
        }
        else if (S.substr(pos, 3) == "chu")
        {
            pos += 3;
        }
        else return false;
    }
    return true;
}

int main() 
{
    string S;
    cin >> S;
    if (check(S)) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
