#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() 
{
    int N, ans = 0;
    cin >> N;
    vector<int> B(N);
    unordered_set<int> us;

    for (int i = 0; i < N; i++) 
    {
        cin >> B[i];
        us.insert(B[i]);
    }

    for (int val : us) 
    {
        int max_len = 0, cur_len = 0, prev = -1;

        for (int num : B) 
        {
            if (num == val) continue;
            if (num == prev) cur_len++;
            else cur_len = 1;
            prev = num;
            max_len = max(max_len, cur_len);
        }
        ans = max(ans, max_len);
    }

    cout << ans << '\n';
    return 0;
}
