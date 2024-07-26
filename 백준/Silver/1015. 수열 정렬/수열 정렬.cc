#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int a[1001], b[1001], visited[1001];
vector <int> v;

int main() 
{
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b, b + n);

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (a[i] == b[j] && !visited[j]) 
            {
                visited[j] = true;
                v.push_back(j);
                break;
            }
        }
    }
    for (auto p : v) 
        cout << p << ' ';
}