#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() 
{
    int N; 
    cin >> N;
    int cnt = 0;

    for (int i = 0; i < N; ++i) 
    {
        string word;
        cin >> word;

        stack<char> s;
        for (char c : word) 
        {
            if (!s.empty() && s.top() == c) 
                s.pop();  
            else s.push(c); 
        }

        if (s.empty()) 
            cnt++;
    }

    cout << cnt << '\n';
    return 0;
}
