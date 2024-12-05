#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

string create_key(vector<int>& counts) 
{
    return to_string(counts[0]) + "," + to_string(counts[1]) + "," + to_string(counts[2]) + "," + to_string(counts[3]);
}

int main() 
{
    int T;
    cin >> T;

    while (T--) 
    {
        int k;
        string W; 
        cin >> k >> W;

        int n = W.size();
        unordered_map<string, int> freq; 
        vector<int> cnt(4, 0); // A, C, G, T

        for (int i = 0; i < k; i++) 
        {
            if (W[i] == 'A') cnt[0]++;
            else if (W[i] == 'C') cnt[1]++;
            else if (W[i] == 'G') cnt[2]++;
            else if (W[i] == 'T') cnt[3]++;
        }

        string key = create_key(cnt);
        freq[key]++;

        for (int i = k; i < n; ++i) 
        {
            if (W[i - k] == 'A') cnt[0]--;
            else if (W[i - k] == 'C') cnt[1]--;
            else if (W[i - k] == 'G') cnt[2]--;
            else if (W[i - k] == 'T') cnt[3]--;

            if (W[i] == 'A') cnt[0]++;
            else if (W[i] == 'C') cnt[1]++;
            else if (W[i] == 'G') cnt[2]++;
            else if (W[i] == 'T') cnt[3]++;

            key = create_key(cnt);
            freq[key]++;
        }

        int ans = 0;
        for (auto& a : freq) 
            ans = max(ans, a.second);
        

        cout << ans << '\n';
    }

    return 0;
}
