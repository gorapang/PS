#include <iostream>
using namespace std;

int main() 
{
    int X;
    cin >> X;

    int diag = 1;
    int sum = 1; 


    while (sum < X) 
    {
        diag++;
        sum += diag;
    }

    int diag_idx = X - (sum - diag); 
    int a, b;

    if (diag % 2 == 0) 
    { 
        a = diag_idx;
        b = diag - diag_idx + 1;
    }
    else 
    { 
        a = diag - diag_idx + 1;
        b = diag_idx;
    }

    cout << a << '/' << b << '\n';

    return 0;
}
