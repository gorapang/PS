#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int>& snow) 
{
    int minutes = 0;

    sort(snow.rbegin(), snow.rend());

    while (snow[0] > 0) 
    {  
        if (snow.size() > 1 && snow[1] > 0) 
        {
            snow[0]--;
            snow[1]--;
        }
        else snow[0]--;
        
        sort(snow.rbegin(), snow.rend());
        minutes++;

        if (minutes > 1440) 
            return -1;

    }

    return minutes;
}

int main() 
{
    int N;
    cin >> N;

    vector<int> snow(N);
    for (int i = 0; i < N; i++) 
        cin >> snow[i];
    
    cout << solve(snow) << '\n';

    return 0;
}
