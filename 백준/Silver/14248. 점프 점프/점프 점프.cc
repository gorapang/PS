#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

int n, s;
bool visited[100001];
int arr[100001];


void dfs(int start)
{
	if (start < 1 || start > n) return;

	visited[start] = true;

	dfs(start + arr[start]);
	dfs(start - arr[start]);

}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	cin >> s;

	dfs(s);

	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (visited[i] == true) ans++;

	cout << ans << '\n';

	return 0;
}