#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    unordered_map<string, bool> mp;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name, cmd;
        cin >> name >> cmd;
        if (cmd == "enter") {
            mp[name] = true;
        }
        else if (cmd == "leave") {
            mp[name] = false;
        }
    }
    int ans = 0;
    vector<string> v;
    for (auto a : mp) {
        if (a.second == true)
            v.push_back(a.first);
    }

    sort(v.begin(), v.end(), greater<string>());
    for (auto a : v)
        cout << a << '\n';
    return 0;
}
