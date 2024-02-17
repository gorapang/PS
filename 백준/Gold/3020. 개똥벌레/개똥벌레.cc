#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <math.h>
#define MAX 200000
using namespace std;

int n, h;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> h;
	vector<int> high(h+1, 0); //high[i]는 길이 i인 종유석의 개수
	vector<int> low(h+1, 0);

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		if (i % 2 == 0)
			low[tmp]++;
		else
			high[tmp]++;
	}

	for (int i = h - 1; i >= 0; i--)
	{
		high[i] += high[i + 1];
		low[i] += low[i + 1];
	}

	//for (int i = 1; i <= h; i++) cout << a[i] << ' ';
	//cout << '\n';
	//for (int i = 1; i <= h; i++) cout << b[i] << ' ';
	//cout << '\n';


	reverse(low.begin() + 1, low.end());

	int ans = MAX, cnt = 0;
	for (int i = 1; i <= h; i++)
	{
		int tmp = high[i] + low[i];
		ans = min(ans, tmp);
	}

	for (int i = 1; i <= h; i++)
	{
		if (high[i] + low[i] == ans) cnt++;
	}

	cout << ans << ' ' << cnt << '\n';
	return 0;
}