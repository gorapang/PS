#include <iostream>
#include <map>
using namespace std;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;

	map<string, string> mp;
	for (int i = 0; i < n; i++)
	{
		string url, pw;
		cin >> url >> pw;
		mp[url] = pw;
	}

	for (int i = 0; i < m; i++)
	{
		string key;
		cin >> key;
		cout << mp[key] << '\n';
	}
	return 0;
}