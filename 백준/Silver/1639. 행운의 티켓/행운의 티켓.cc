#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int get_sum(string s, int start, int length) 
{
    int sum = 0;
    for (int i = start; i < start + length; i++) 
    {
        sum += s[i] - '0';
    }
    return sum;
}

int main() 
{
    string s;
    cin >> s;

    int max_len = 0;
    int n = s.size();

    for (int length = 2; length <= n; length += 2) 
    {
        for (int i = 0; i <= n - length; i++) 
        {
            int mid = length / 2;
            int left_sum = get_sum(s, i, mid);
            int right_sum = get_sum(s, i + mid, mid);

            if (left_sum == right_sum) 
            {
                max_len = max(max_len, length);
            }
        }
    }

    cout << max_len << '\n';
    return 0;
}
