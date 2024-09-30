#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int map[5][5];
bool check[5][5];

void num_check(int num)
{
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (map[i][j] == num)
                check[i][j] = check;
}

int bingo_check()
{
    int cnt = 0;

    //가로
    for (int i = 0; i < 5; i++)
    {
        bool flag = true;
        for (int j = 0; j < 5; j++)
        {
            if (check[i][j] == false) flag = false;
        }
        if (flag == true) cnt++;
    }

    //세로
    for (int i = 0; i < 5; i++)
    {
        bool flag = true;
        for (int j = 0; j < 5; j++)
        {
            if (check[j][i] == false) flag = false;
        }
        if (flag == true) cnt++;
    }

    //대각선
    int flag = true;
    for (int i = 0; i < 5; i++)
    {
        if (check[i][i] == false) flag = false;
    }
    if (flag) cnt++;

    flag = true;
    for (int i = 0; i < 5; i++)
    {
        if (check[i][4 - i] == false) flag = false;
    }
    if (flag) cnt++;

    return cnt;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> map[i][j];

    for (int i = 1; i <= 25; i++)
    {
        int num;
        cin >> num;
        num_check(num);
        if (bingo_check() >= 3)
        {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}