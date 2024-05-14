#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	priority_queue<long long> pq;

	for (int i = 0; i < n; i++)
	{
		long long tmp;
		cin >> tmp;
		pq.push(-tmp);
	}
	
	while (m--)
	{
		long long a = -pq.top(); pq.pop();
		long long b = -pq.top(); pq.pop();
		long long c = a + b;
		pq.push(-c); pq.push(-c);
	}

	long long ans = 0;
	while (!pq.empty())
	{
		ans += -pq.top();
		pq.pop();
	}

	cout << ans << '\n';

	return 0;
}