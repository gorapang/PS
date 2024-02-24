#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 999'999'999
using namespace std;

int v, e, k;
vector<pair<int, int>> adj[20001];
int dist[20001];
int visited[20001];


void Dijkstra(int start)
{
	dist[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ dist[start], start });

	while (!pq.empty())
	{
		//방문하지 않은 노드 중 거리가 최소인 노드 선택
		int cur = pq.top().second;
		int cur_cost = -pq.top().first;
		pq.pop();

		for (int i = 0; i < adj[cur].size(); i++)
		{
			int next = adj[cur][i].first;
			int next_dist = adj[cur][i].second;

			if (dist[next] > cur_cost + next_dist)
			{
				dist[next] = cur_cost + next_dist;
				pq.push(make_pair(-dist[next], next));
			}
		}
	}
}




int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> v >> e;
	cin >> k;

	for (int i = 1; i <= v; i++)
	{
		dist[i] = INF;
		visited[i] = false;
	}

	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
	}

	Dijkstra(k);

	for (int i = 1; i <= v; i++)
	{
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << '\n';
	}

	
	return 0;
}