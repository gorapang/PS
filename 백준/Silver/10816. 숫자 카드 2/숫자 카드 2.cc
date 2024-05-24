#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n, m;

	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;

		cout << upper_bound(v.begin(), v.end(), num) - lower_bound(v.begin(), v.end(), num) << ' ';
	}

	

	return 0;
}