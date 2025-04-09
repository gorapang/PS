#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    int N, M;
    cin >> N >> M;

    int min_pack = 1001;
    int min_one = 1001;

    for (int i = 0; i < M; ++i) 
    {
        int pkg, one;
        cin >> pkg >> one;
        min_pack = min(min_pack, pkg);
        min_one = min(min_one, one);
    }

    int cost1 = min_one * N;
    int cost2 = ((N + 5) / 6) * min_pack;
    int cost3 = (N / 6) * min_pack + (N % 6) * min_one;

    cout << min({ cost1, cost2, cost3 }) << '\n';

    return 0;
}
