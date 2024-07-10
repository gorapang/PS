#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k, n, f;
bool adj[901][901];
vector<int> v;

bool is_friend(int x)
{
    for (auto f : v)
        if (adj[x][f] == false)
            return false;

    return true;
}

bool dfs(int cur) 
{
    if (v.size() == k) 
        return true;

    for (int i = cur + 1; i <= n; i++)
    {
        if (!is_friend(i)) continue;

        v.push_back(i);
        if (dfs(i)) return true;
        v.pop_back();

    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> k >> n >> f;
    for (int i = 0; i < f; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a][b] = adj[b][a] = true;
    }

    for (int i = 1; i <= n; i++) 
    {
        v.push_back(i);
        if (dfs(i)) 
        {
            for (auto f : v)
                cout << f << '\n';
            return 0;
        }
        v.clear();
    }

    cout << -1 << '\n';
    return 0;
}
