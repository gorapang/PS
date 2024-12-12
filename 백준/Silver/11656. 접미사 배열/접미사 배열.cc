#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    string str;
    cin >> str;

    vector<string> v;

    for (int i = 0; i < str.length(); i++) 
        v.push_back(str.substr(i));
    
    sort(v.begin(), v.end());


    for (const string& s : v)
        cout << s << '\n';

    return 0;
}
