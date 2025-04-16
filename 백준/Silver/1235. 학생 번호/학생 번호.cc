#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> V(N);
    int max_length = 0;

    for (int i = 0; i < N; i++) 
    {
        cin >> V[i];
        max_length = max(max_length, (int)V[i].size());
    }

    for (int k = 1; k <= max_length; k++) 
    {
        unordered_set<string> unique_numbers;

        for (int i = 0; i < N; i++) 
            unique_numbers.insert(V[i].substr(V[i].size() - k));
        

        if (unique_numbers.size() == N) 
        {
            cout << k << '\n';
            return 0;
        }
    }

    return 0;
}
