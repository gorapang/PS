#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;

    deque<pair<int, int>> dq; // 풍선번호, 이동

    for (int i = 1; i <= N; i++) 
    {
        int move;
        cin >> move;
        dq.push_back({ i, move });
    }

    vector<int> res;

    while (!dq.empty()) 
    {
        pair<int, int> current = dq.front();
        dq.pop_front();
        res.push_back(current.first);

        if (dq.empty()) break;

        int m = current.second;

        if (m > 0) 
        {
            for (int i = 0; i < m - 1; i++) 
            {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else {
            for (int i = 0; i < -m; i++) 
            {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }

    for (auto a : res) 
    {
        cout << a << ' ';
    }
    cout << '\n';;

    return 0;
}
