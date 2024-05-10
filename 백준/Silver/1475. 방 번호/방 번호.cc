#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	int number[10] = {};
	while (0 < n)
	{
		number[n % 10]++;
		n /= 10;
	}

	int ans = 1;
	for (int i = 0; i < 10; i++)
	{
		if (i == 6 || i == 9) continue;
		ans = max(ans, number[i]);
	}

	ans = max(ans, (number[6] + number[9] + 1) / 2);
	cout << ans << '\n';

	return 0;
}