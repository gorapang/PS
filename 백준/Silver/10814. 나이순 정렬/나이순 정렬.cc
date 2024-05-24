#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, string> a, pair<int, string>b)
{
	return a.first < b.first;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	vector<pair<int, string>> v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i].first >> v[i].second;
	}

	stable_sort(v.begin(), v.end(), compare);

	for (int i = 0; i < N; i++)
	{
		cout << v[i].first << ' ' << v[i].second << '\n';
	}

	return 0;
}