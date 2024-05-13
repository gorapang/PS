#include <iostream>
#include <vector>

using namespace std;


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int tc;
		cin >> tc;

		int score[101] = { 0, }; // score[i]: i점이 나온 횟수
		for (int i = 0; i < 1000; i++)
		{
			int n;
			cin >> n;
			score[n]++;
		}

		int ans = -1; // 최빈값
		int max_count = 0;

		for (int i = 0; i <= 100; i++)
		{
			if (score[i] >= max_count)
			{
				max_count = score[i];
				ans = i;
			}
		}

		cout << '#' << tc << ' ' << ans << '\n';
	}

	return 0;
}