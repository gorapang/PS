#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

string str[3];
int num[3];
int value[26];
bool alphabet_exist[26];
bool num_visited[10];
vector<int> used_alphabet;
bool flag;

int get_number(string str) {
    int res = 0;
    int idx;
    for (int i = 0; i < str.size(); i++)
    {
        idx = str[i] - 'A';
        res = res * 10 + value[idx];
    }
    return res;
}

void dfs(int depth) {
    if (depth == used_alphabet.size()) {
        for (int i = 0; i < 3; i++)
            num[i] = get_number(str[i]);
        if (num[0] + num[1] == num[2])
            flag = true;
    }

    else {
        for (int i = 0; i < 10; i++)
        {
            if (!num_visited[i]) {
                num_visited[i] = true;
                value[used_alphabet[depth]] = i;
                dfs(depth + 1);
                num_visited[i] = false;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for (int i = 0; i < 3; i++)
    {
        cin >> str[i];
        for (int j = 0; j < str[i].size(); j++) 
        {
            int idx = str[i][j] - 'A';
            alphabet_exist[idx] = true;
        }
    }
        
    for (int i = 0; i < 26; i++)
    {
        if (alphabet_exist[i]) 
            used_alphabet.push_back(i);
    }

    dfs(0);
    if (flag) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
