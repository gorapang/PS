#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++) 
        cin >> v[i];

    vector<int> res(N, 0);

    for (int i = 0; i < N; i++) 
    {
        int cnt = v[i];
        for (int j = 0; j < N; j++) 
        {
            if (cnt == 0 && res[j] == 0) 
            {
                res[j] = i + 1;
                break;
            }
            else if (res[j] == 0) 
            {
                --cnt;
            }
        }
    }

    for (int i = 0; i < N; i++) 
        cout << res[i] << " ";
    

    return 0;
}
