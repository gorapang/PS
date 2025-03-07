#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() 
{
    int N, K;
    cin >> N >> K;
    vector<int> v(N);

    for (int i = 0; i < N; i++) 
        cin >> v[i];
    

    vector<int> index;

    for (int i = 0; i < N; i++) 
        if (v[i] == 1) 
            index.push_back(i);
      
   

    if (index.size() < K) 
    {
        cout << -1 << '\n';
        return 0;
    }

    int men_len = INT_MAX;

    for (int i = 0; i <= index.size() - K; i++) 
    {
        int length = index[i + K - 1] - index[i] + 1;
        men_len = min(men_len, length);
    }

    cout << men_len << '\n';
    return 0;
}