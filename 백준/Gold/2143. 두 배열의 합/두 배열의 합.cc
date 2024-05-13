#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long t, n, m, a[1001], b[1001];
long long ans = 0;
vector<int> asub, bsub;

int count(vector<int> v, int n)
{
	int cnt = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == n) cnt++;
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> t >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> b[i];

	//부분합 만들기
	int tmp;
	for (int i = 0; i < n; i++)
	{
		tmp = 0;
		for (int j = i; j < n; j++)
		{
			tmp += a[j];
			asub.push_back(tmp);
		}
	}

	for (int i = 0; i < m; i++)
	{
		tmp = 0;
		for (int j = i; j < m; j++)
		{
			tmp += b[j];
			bsub.push_back(tmp);
		}
	}


	//정렬
	sort(bsub.begin(), bsub.end());


	for (int i = 0; i < asub.size(); i++)
	{
		int target = t - asub[i];
		int low = lower_bound(bsub.begin(), bsub.end(), target) - bsub.begin();
		int high = upper_bound(bsub.begin(), bsub.end(), target) - bsub.begin();
		ans += (high - low);
	}

	cout << ans << '\n';
	return 0;
}