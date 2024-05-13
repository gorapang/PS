#include <iostream>
#include <vector>
#include <string>
using namespace std;

int dist(string a, string b)
{
	int res = 0;
	for (int i = 0; i < 4; i++)
		if (a[i] != b[i])
			res++;

	return res;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		vector<string> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];

		if (n > 32)
		{
			cout << "0\n";
			continue;
		}

		int ans = 13;

		for (int i = 0; i < n - 2; i++)
			for (int j = i + 1; j < n - 1; j++)
				for (int k = j + 1; k < n; k++)
				{
					int cur = dist(v[i], v[j]) + dist(v[j], v[k]) + dist(v[i], v[k]);
					ans = min(ans, cur);
				}
		
		cout << ans << '\n';
	}

	return 0;
}