#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <queue>
#define INF 987654321
using namespace std;

int n;
int max_num;
vector<int> v;
vector<bool> visited;
int ans = 0;

int bfs(int start, int end)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;

	int depth = 0;
	bool break_flag = false;

	while (!q.empty())
	{
		if (break_flag) break;

		int qsize = q.size();
		for (int qs = 0; qs < qsize; qs++)
		{
			int nx = q.front();

			if (nx == end)
			{
				break_flag = true;
				depth--;
				break;
			}

			q.pop();

			for (int i = 1; i <= n; i++)
			{
				if (abs(i - nx) % v[nx] == 0 && !visited[i])
				{
					q.push(i);
					visited[i] = true;
				}
			}
		}
		depth++;
	}

	if (break_flag == false) depth = -1;
	return depth;
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	v.resize(n + 1);
	visited.resize(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
		max_num = max(max_num, v[i]);
	}

	int a, b;
	cin >> a >> b;

	int ans = bfs(a, b);
	cout << ans << '\n';

	return 0;
}