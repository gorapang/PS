#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	
	deque<int> dq;
	for (int i = 1; i <= n; i++)
		dq.push_back(i);

	int left, right;
	int cnt = 0;

	while (m--)
	{
		int a;
		cin >> a;

		for (int i = 0; i < dq.size(); i++)
		{
			if (dq[i] == a)
			{
				left = i;
				right = dq.size() - i;
				break;
			}
		}

		if (left <= right)
		{
			while (1)
			{
				if (dq.front() == a) break;
				dq.push_back(dq.front());
				dq.pop_front();
				cnt++;
			}
			dq.pop_front();
		}
		else {
			cnt++;
			while (1) {
				if (dq.back() == a)
					break;

				dq.push_front(dq.back());
				dq.pop_back();
				cnt++;

			}
			dq.pop_back();
		}
	}

	cout << cnt << '\n';

	return 0;
}