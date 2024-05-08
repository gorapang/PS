#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;

	queue<int> q;

	for (int i = 1; i <= n; i++)
		q.push(i);
		
	while (q.size() > 1)
	{
		int start = q.front();

		if (q.size() >= k)
		{
			for (int i = 1; i <= k; i++) q.pop();
			q.push(start);
			
		}

		else if (q.size() < k)
		{
			while (!q.empty()) q.pop();
			q.push(start);
		}

		if (q.size() == 1) break;

	}

	cout << q.front() << '\n';



	return 0;
}