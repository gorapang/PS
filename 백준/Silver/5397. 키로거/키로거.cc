#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;

    while (t--) 
    {
        string str;
        cin >> str;

        stack<char> left, right;

        for (char ch : str) 
        {
            if (ch == '<') 
            {
                if (!left.empty()) 
                {
                    right.push(left.top());
                    left.pop();
                }
            }
            else if (ch == '>') 
            {
                if (!right.empty()) 
                {
                    left.push(right.top());
                    right.pop();
                }
            }
            else if (ch == '-') 
            {
                if (!left.empty()) 
                {
                    left.pop();
                }
            }
            else 
            {
                left.push(ch);
            }
        }

        string result;
        while (!left.empty()) 
        {
            result.push_back(left.top());
            left.pop();
        }
        reverse(result.begin(), result.end());

        while (!right.empty()) 
        {
            result.push_back(right.top());
            right.pop();
        }

        cout << result << '\n';
    }

    return 0;
}
