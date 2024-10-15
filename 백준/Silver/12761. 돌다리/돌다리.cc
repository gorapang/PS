#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int A, B, N, M;
bool visited[100001];

int bfs(int N, int M)
{
	queue<int> q;
	q.push(N);
	visited[N] = true;
	int qsize = 0;
	int depth = 0;

	while (!q.empty())
	{
		qsize = q.size();
		for (int i = 0; i < qsize; i++)
		{
			int nx = q.front();
			q.pop();

			if (nx == M)
			{
				return depth;
			}

			int candidate[8] = { nx + 1,nx - 1,nx + A,nx - A,nx + B,nx - B,nx * A,nx * B };
			for (int i = 0; i < 8; i++)
			{
				if (candidate[i] < 0 || candidate[i] >100000 || visited[candidate[i]]) continue;
				visited[candidate[i]] = true;
				q.push(candidate[i]);
			}

		}
		depth++;
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> A >> B >> N >> M;

	cout << bfs(N, M) << '\n';


	return 0;
}