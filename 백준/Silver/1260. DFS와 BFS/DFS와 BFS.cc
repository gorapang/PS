#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
int n, m, v;
int arr[1001][1001];
int visited[1001];

int dfs(int start)
{
	visited[start] = true;
	cout << start << " ";

	for (int i = 1; i <= n; i++)
		if (arr[start][i] == 1 && visited[i] == 0)
			dfs(i);

	return 0;
}

int bfs(int start)
{
	q.push(start);
	visited[start] = true;
	cout << start << " ";

	while (!q.empty())
	{
		start = q.front();
		q.pop();

		for (int i = 1; i <= n; i++)
		{
			if (arr[start][i] == 1 && visited[i] == 0)
			{
				q.push(i);
				visited[i] = true;
				cout << i << " ";
			}
		}	
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	dfs(v);
	cout << "\n";

	for (int i = 1; i < 1001; i++)
		visited[i] = 0;

	bfs(v);
	return 0;
}