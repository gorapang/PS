#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    int N, M;
    cin >> N >> M;

    vector<int> P(M);
    for (int i = 0; i < M; i++) 
        cin >> P[i];
    

    sort(P.begin(), P.end()); 

    int max_profit = 0;
    int best_price = 0;

    for (int i = 0; i < M; i++) 
    {
        int price = P[i];
        int count = min(N, M - i);  
        int profit = price * count; 

        if (profit > max_profit) 
        {
            max_profit = profit;
            best_price = price;
        }
    }

    cout << best_price << ' ' << max_profit << '\n';

    return 0;
}
