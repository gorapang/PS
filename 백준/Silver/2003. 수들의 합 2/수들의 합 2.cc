#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, arr[10001];
int sum;
int ans = 0;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		sum = 0;
		for (int j = i; j < n; j++)
		{
			sum += arr[j];
			if (sum == m) ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}