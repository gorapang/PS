#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<int, int>>tree[200001];
bool visited[200001];

int trunk_len, branch_len, start_branch, end_branch;

void find_trunk(int node, int len)
{
    visited[node] = true;
    trunk_len = len;
    start_branch = node;

    if (tree[node].size() > 2) return;

    for (auto next : tree[node]) 
    {
        if (visited[next.first]) continue;
        
        visited[next.first] = true;
        find_trunk(next.first, len + next.second);
    }
}

void find_longest_branch(int node, int len)
{
    visited[node] = true;
    if (len > branch_len) 
    {
        end_branch = node;
        branch_len = len;
    }

    for (auto next : tree[node]) 
    {
        if (visited[next.first]) continue;

        visited[next.first] = true;
        find_longest_branch(next.first, len + next.second);
    }
}


int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, R; 
    cin >> N >> R;

    for (int i = 0; i < N - 1; i++) 
    {
        int a, b, c; 
        cin >> a >> b >> c;
        tree[a].push_back({ b,c });
        tree[b].push_back({ a,c });
    }

    if (tree[R].size() >= 2) 
    {
        find_trunk(R, 0);
        trunk_len = 0;
        memset(visited, 0, sizeof(visited));
        find_longest_branch(R, 0);
    }

    else 
    {
        find_trunk(R, 0);
        find_longest_branch(start_branch, 0);
    }

    cout << trunk_len << ' ' << branch_len;

}