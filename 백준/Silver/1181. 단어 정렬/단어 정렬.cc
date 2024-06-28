#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool comp(string a, string b)
{
	if (a.length() == b.length())
		return a < b;
	return a.length() < b.length();
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	vector<string> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end(), comp);
	v.erase(unique(v.begin(), v.end()), v.end());

	for (auto x : v)
		cout << x << '\n';

	return 0;
}
