#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool adj[13][13];
int degree[13];

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 0; i < 12; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a][b] = adj[b][a] = true;
        degree[a]++; degree[b]++;
    }

    for (int i = 1; i <= 12; i++)
    {
        if (degree[i] == 3)
        {

            int cnt = 0;
            for (int j = 1; j <= 12; j++)
            {
                if (adj[i][j]) cnt += degree[j];
            }
            if (cnt == 6)
            {
                cout << i << '\n';
                return 0;
            }
        }
    }
    return 0;
}
