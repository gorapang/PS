#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	
	stack<int> s;
	vector<int> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	int cnt = 1;
	for (int i = 0; i < n; i++)
	{
		if (v[i] == cnt) cnt++;
		else s.push(v[i]);

		while (!s.empty() && s.top() == cnt)
		{
			s.pop();
			cnt++;
		}
	}
	
	if (s.empty()) cout << "Nice\n";
	else cout << "Sad\n";

	return 0;
}