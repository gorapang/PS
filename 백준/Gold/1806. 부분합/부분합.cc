#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, s, arr[100001];
int sum = 0;
int len;
int min_len = 100002;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int start = 0, end = 0;
	while (start <= end)
	{
		if (sum >= s)
		{
			min_len = min((end - start), min_len);
			sum -= arr[start];
			start++;
		}
		else if (end == n) break;
		else
		{
			sum += arr[end];
			end++;
		}
	}

	if (min_len == 100002) cout << 0 << '\n';
	else cout << min_len << '\n';
	return 0;
}