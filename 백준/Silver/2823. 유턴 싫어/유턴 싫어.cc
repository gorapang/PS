#include <iostream>
#include <vector>

using namespace std;

int R, C;
char arr[10][10];

bool not_okay(int x, int y) 
{
    int cnt = 0;

    if (arr[x - 1][y] == '.') cnt++;    
    if (arr[x + 1][y] == '.') cnt++;   
    if (arr[x][y - 1] == '.') cnt++;       
    if (arr[x][y + 1] == '.') cnt++;    

    if (cnt == 1) return true;
    return false;
}

int main() 
{
    cin >> R >> C;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> arr[i][j];
    
    for (int i = 0; i < R; i++) 
    {
        for (int j = 0; j < C; j++) 
        {
            if (arr[i][j] == '.' && not_okay(i, j)) 
            {
                cout << 1 << '\n'; 
                return 0;
            }
        }
    }

    cout << 0 << '\n'; 
    return 0;
}
