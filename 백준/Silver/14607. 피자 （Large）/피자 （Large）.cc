#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;


int main() 
{
	long long n;
	cin >> n;
	long long ans = n * (n - 1) / 2;
	cout << ans << '\n';
	return 0;
}
