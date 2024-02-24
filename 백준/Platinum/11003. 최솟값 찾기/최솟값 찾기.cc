#include <iostream>
#include <deque>
using namespace std;

int n, l, d;
deque<pair<int, int>> dq;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> l;
	int now;
	for (int i = 0; i < n; i++)
	{
		cin >> now;

		while (dq.size() != 0 && dq.back().first > now)
			dq.pop_back();

		dq.push_back(make_pair(now, i));

		while (dq.front().second <= i - l)
			dq.pop_front();

		cout << dq.front().first << ' ';
	}
		

	return 0;
}