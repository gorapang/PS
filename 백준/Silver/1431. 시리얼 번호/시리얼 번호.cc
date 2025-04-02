#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sum_of_digits(string s) 
{
    int sum = 0;
    for (char ch : s) 
    {
        if (ch >= '0' && ch <= '9')
        {
            sum += ch - '0';
        }
    }
    return sum;
}


bool comp(string& a, string& b) 
{
    if (a.length() != b.length()) return a.length() < b.length();
    
    int sumA = sum_of_digits(a);
    int sumB = sum_of_digits(b);
    if (sumA != sumB) return sumA < sumB;
    
    return a < b;
}

int main() {
    int n;
    cin >> n;

    vector<string> v(n);
    for (int i = 0; i < n; i++) 
        cin >> v[i];
    

    sort(v.begin(), v.end(), comp);

    for (string s : v) 
        cout << s << '\n';

    return 0;
}
