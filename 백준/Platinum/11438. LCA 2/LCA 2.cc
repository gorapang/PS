#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <math.h>
#include <list>
#include <queue>
using namespace std;

int n, m;
int k;
vector<vector<int>> ADJ;
vector<bool> visited;
vector<int> D;
vector<vector<int>> parent;

void bfs(int n)
{
	queue<int> q;
	q.push(n);
	visited[n] = true;
	
	int depth = 0;

	while (!q.empty())
	{
		int qsize = q.size();
		for (int i = 0; i < qsize; i++)
		{
			int cur = q.front();
			D[cur] = depth;
			q.pop();

			for (int j = 0; j < ADJ[cur].size(); j++)
			{
				int next = ADJ[cur][j];
				if (!visited[next])
				{
					q.push(next);
					visited[next] = true;
					parent[0][next] = cur;
				}
			}
		}
		depth++;

	}	
}



int find_LCA(int a, int b)
{
	if (D[a] != D[b])
	{
		if (D[a] > D[b]) swap(a, b); //항상 b가 크도록 함

		//깊이 맞추기
		for (int i = k; i >= 0; i--)
		{
			if (pow(2, i) <= D[b] - D[a])
			{
				b = parent[i][b];
			}
		}
	}

	if (a == b) return a;


	//LCA 찾기
	int res_a, res_b;
	for (int i = k; i >= 0; i--)
	{
		if (parent[i][a] != parent[i][b])
		{
			if (parent[i][a] != 0) //a가 1인 경우 부모로 올라가지 않음
			{
				a = parent[i][a];
				b = parent[i][b];
			}
		}
	}
	a = parent[0][a];
	return a;
}



int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;

	ADJ.resize(n + 1);
	visited.resize(n + 1, false);
	D.resize(n + 1);

	for (int i = 0; i < n-1; i++)
	{
		int a, b;
		cin >> a >> b;
		ADJ[a].push_back(b);
		ADJ[b].push_back(a);
	}

	k = floor(log2(n));
	//cout << "K: " << k << '\n';
	parent.resize(k + 1, vector<int>(n + 1));

	//bfs
	bfs(1);


	//dp
	for (int i = 1; i <= k; i++)
	{
		for (int j = 2; j <= n; j++)
		{
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
		}
	}



	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		cout << find_LCA(a, b) << '\n';
	}

	return 0;
}