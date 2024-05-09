#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	stack<int> s;
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> NGE(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	for (int i = 0; i < n; i++)
	{
		while (!s.empty() && v[s.top()] < v[i])
		{
			NGE[s.top()] = v[i];
			s.pop();
		}
		s.push(i);
	}


	while (!s.empty())
	{
		NGE[s.top()] = -1;
		s.pop();
	}

	for (int i = 0; i < n; i++)
		cout << NGE[i] << ' ';
	cout << '\n';


	return 0;
}