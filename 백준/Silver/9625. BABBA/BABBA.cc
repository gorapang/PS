#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
	int k;
	cin >> k;
	int a[46];
	int b[46];

	a[0] = 1, a[1] = 0;
	b[0] = 0, b[1] = 1;
	for (int i = 2; i <= k; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
		b[i] = b[i - 1] + b[i - 2];
	}

	cout << a[k] << ' ' << b[k] << '\n';

}
