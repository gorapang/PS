#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) 
        cin >> A[i];

    nth_element(A.begin(), A.begin() + (K - 1), A.end());

    cout << A[K - 1] << '\n';

    return 0;
}
