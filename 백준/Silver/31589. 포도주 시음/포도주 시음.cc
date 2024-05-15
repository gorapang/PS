#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	v.push_back(0);
	sort(v.begin(), v.end());

	long long ans = 0;
	bool flag = false;
	int s = 0, e = n;

	while (k--)
	{
		if (!flag)
			ans += (v[e] - v[s]);

		flag = !flag;
		if (flag) s++;
		else e--;
	}

	cout << ans << '\n';

	return 0;
}