#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    if (N > M) cout << 0 << '\n';
    else
    {
        long long NF = 1;
        for (int i = 1; i <= N; i++)
        {
            NF *= i;
            NF %= M;
        }

        cout << NF % M << '\n';
    }

    return 0;
}
