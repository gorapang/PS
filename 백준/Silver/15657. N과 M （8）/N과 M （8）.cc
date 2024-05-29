#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int n, m;
vector<int> v;
int arr[9];


void backtracking(int num, int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
	}

	else
	{
		for (int i = num; i < n; i++)
		{
			arr[k] = v[i];
			backtracking(i, k + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	backtracking(0, 0);

	return 0;
}