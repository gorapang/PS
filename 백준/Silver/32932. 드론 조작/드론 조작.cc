#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool arr[1001][1001];

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++) 
    {
        int x, y;
        cin >> x >> y;
        arr[x + 500][y + 500] = true;
    }

    string cmd;
    cin >> cmd;

    int x = 500, y = 500;
    for (char c : cmd) 
    {
        int nx = x, ny = y;

        if (c == 'U') ny++;
        else if (c == 'D') ny--;
        else if (c == 'R') nx++;
        else if (c == 'L') nx--;

        if (!arr[nx][ny]) 
        { 
            x = nx;
            y = ny;
        }
    }

    cout << x - 500 << ' ' << y - 500 << '\n'; 
    return 0;
}
