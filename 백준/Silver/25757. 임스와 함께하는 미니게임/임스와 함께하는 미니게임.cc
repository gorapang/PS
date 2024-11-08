#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    int N;              
    char c;      
    cin >> N >> c;

    int required;
    if (c == 'Y') required = 1;
    else if (c == 'F') required = 2;
    else if (c == 'O') required = 3;

    unordered_set<string> us;  

    for (int i = 0; i < N; i++) 
    {
        string name;
        cin >> name;
        us.insert(name); 
    }

    cout << us.size() / required << '\n';
    return 0;
}
