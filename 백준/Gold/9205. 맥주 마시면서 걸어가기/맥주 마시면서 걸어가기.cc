#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;

int t;

typedef struct point {
	int x, y;
}point;

int n;
point home, festival;
point store[100];
bool visited[100];

bool bfs(int n)
{
	queue<pair<int, int>> q;
	q.push({ home.x, home.y });

	while (!q.empty()) 
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (abs(festival.x - x) + abs(festival.y - y) <= 1000) 
			return true;
		
		for (int i = 0; i < n; i++)
		{
			if (visited[i]) continue;

			if (abs(store[i].x - x) + abs(store[i].y - y) <= 1000)
			{
				visited[i] = true;
				q.push({ store[i].x, store[i].y });
			}
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> t;

	while (t--)
	{
		cin >> n;
		
		cin >> home.x >> home.y;

		for (int i = 0; i < n; i++)
			cin >> store[i].x >> store[i].y;

		cin >> festival.x >> festival.y;

		bool flag = bfs(n);
		if (flag) cout << "happy\n";
		else cout << "sad\n";

		memset(visited, false, sizeof(visited));
	}

	return 0;
}