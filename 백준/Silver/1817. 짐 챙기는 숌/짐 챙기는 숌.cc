#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int N, M;
    cin >> N >> M;

    if (N == 0) 
    {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> books(N);
    for (int i = 0; i < N; ++i) 
        cin >> books[i];
    

    int cnt = 0;
    int weight = 0;

    for (int i = 0; i < N; ++i) 
    {
        if (weight + books[i] > M) 
        {
            cnt++;
            weight = 0;
        }
        weight += books[i];
    }

    if (weight > 0) cnt++;
    
    cout << cnt << '\n';
    return 0;
}
