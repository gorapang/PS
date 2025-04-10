#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> dna(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> dna[i];
    }

    string res = "";
    int dist = 0;

    for (int i = 0; i < m; ++i)
    {
        int cnt[4] = { 0 }; 
        for (int j = 0; j < n; ++j)
        {
            char c = dna[j][i];
            if (c == 'A') cnt[0]++;
            else if (c == 'C') cnt[1]++;
            else if (c == 'G') cnt[2]++;
            else cnt[3]++;
        }

        int idx = 0;
        for (int k = 1; k < 4; ++k)
        {
            if (cnt[k] > cnt[idx])
            {
                idx = k;
            }
            else if (cnt[k] == cnt[idx] && k < idx)
            {
                idx = k;
            }
        }

        char base = "ACGT"[idx];
        res += base;

        for (int j = 0; j < n; ++j)
        {
            if (dna[j][i] != base)
            {
                dist++;
            }
        }
    }

    cout << res << '\n' << dist << '\n';
    return 0;
}
