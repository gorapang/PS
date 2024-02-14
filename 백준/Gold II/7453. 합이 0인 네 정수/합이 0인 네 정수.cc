#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int n;
long long ans = 0;
int a[4000], b[4000], c[4000], d[4000];

long long count()
{
	long long cnt = 0;
	vector<long long> v, w;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			v.push_back(a[i] + b[j]);
			w.push_back(c[i] + d[j]);
		}
	}

	sort(w.begin(), w.end());

	for (int i = 0; i < v.size(); i++)
	{
		long long target = -v[i];
		int low = lower_bound(w.begin(), w.end(), target) - w.begin();
		int high = upper_bound(w.begin(), w.end(), target) - w.begin();
		cnt += (high - low);
	}

	return cnt;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}

	

	ans += count();

	cout << ans << '\n';
	return 0;
}