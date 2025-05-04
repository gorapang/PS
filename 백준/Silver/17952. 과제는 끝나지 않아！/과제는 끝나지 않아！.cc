#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;

    stack<pair<int, int>> s; 
    int total_score = 0;

    for (int i = 0; i < N; ++i)
    {
        int cmd;
        cin >> cmd;

        if (cmd == 1)
        {
            int A, T;
            cin >> A >> T;
            s.push({ A, T });
        }

        if (!s.empty())
        {
            s.top().second--;

            if (s.top().second == 0)
            {
                total_score += s.top().first; 
                s.pop();
            }
        }
    }

    cout << total_score << '\n';
    return 0;
}
