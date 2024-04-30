#include <iostream>
#include <vector>
using namespace std;

int cnt[10]; //cnt[i]: 과일i의 개수

bool okay(int cnt[10])
{
	int res = 0;
	for (int i = 1; i <= 9; i++)
	{
		if (cnt[i] > 0) res++;
	}

	if (res <= 2) return true;
	else return false;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	
	int ans = 0, start = 0, end = 0;

	vector<int> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	while (end < N)
	{
		if (okay(cnt))
		{
			cnt[v[end]]++;
			end++;
		}
		else
		{
			cnt[v[start]]--;
			start++;
		}

		if (okay(cnt)) ans = max(ans, end - start);
	}

	cout << ans << '\n';

	return 0;
}