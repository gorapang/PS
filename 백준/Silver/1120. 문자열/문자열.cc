#include <iostream>
#include <string>
#include <algorithm> // min 함수 사용을 위해 필요

using namespace std;

string A, B;
int min_difference() 
{
    int min_diff = A.length(); 

    for (int i = 0; i <= B.length() - A.length(); i++) 
    {
        int diff = 0;

        for (int j = 0; j < A.length(); ++j) 
            if (A[j] != B[i + j]) 
                diff++;

        min_diff = min(min_diff, diff);
    }

    return min_diff;
}

int main() 
{

    cin >> A >> B;

    cout << min_difference() << '\n';

    return 0;
}
