#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 999'999'999
using namespace std;

int V, E, K;
vector<vector<pair<int, int>>> adj;
vector<int> dist;

void Dijkstra(int start)
{
	dist[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ -dist[start], start });

	while (!pq.empty())
	{
		int cur_node = pq.top().second;
		int cur_cost = -pq.top().first; //시작 노드에서 현재 노드까지의 거리
		pq.pop();
		
		for (int i = 0; i < adj[cur_node].size(); i++)
		{
			pair<int, int> next = adj[cur_node][i];
			int next_node = next.first;
			int next_cost = next.second; //시작 노드에서 다음 노드까지의 거리
			
			//시작->다음 보다 시작->현재->다음이 더 짧으면
			if (dist[next_node] > cur_cost + next_cost) 
			{
				dist[next_node] = cur_cost + next_cost;
				pq.push({ -dist[next_node], next_node}); // 업데이트한 거리 push
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> V >> E;
	adj.resize(V + 1);
	dist.resize(V + 1);

	for (int i = 1; i <= V; i++)
	{
		dist[i] = INF;
	}

	cin >> K;

	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
	}

	Dijkstra(K);

	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << '\n';
	}

	return 0;
}