#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

	int n, k;

	cin >> n >> k;
	vector<int> v(n);

	int m = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		m = max(m, v[i]);
	}

	long long left = 1; 
	long long right = m;
	long long ans = 0;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		int cnt = 0;

		for (int i = 0; i < n; i++)
			cnt += (v[i] / mid);

		if (cnt >= k)
		{
			ans = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	cout << ans << '\n';

	return 0;
}