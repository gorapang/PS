#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int check(vector<int>& h, int index)
{
	int left1 = h[index - 2];
	int left2 = h[index - 1];
	int right1 = h[index + 1];
	int right2 = h[index + 2];

	int max_h = max(max(max(left1, left2), right1), right2);
	int res = h[index] - max_h;
	res = max(res, 0);
	return res;
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;
		
		vector<int> height(n);
		for (int i = 0; i < n; i++)
			cin >> height[i];

		int ans = 0;

		for (int i = 2; i < n-2; i++)
		{
			ans += check(height, i);
		}

		cout << '#' << test_case << ' ' << ans << '\n';

	}
	return 0;
}