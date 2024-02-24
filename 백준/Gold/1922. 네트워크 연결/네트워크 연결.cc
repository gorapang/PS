#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <math.h>
#include <list>
#include <queue>
using namespace std;

int n, m;
vector<int> parent;

typedef struct edge
{
	int s, e, w;
}edge;

int FIND(int a)
{
	if (parent[a] == a) return a;
	else return parent[a] = FIND(parent[a]);
}

void UNION(int a, int b)
{
	a = FIND(a);
	b = FIND(b);
	parent[a] = b;

}

bool comp(const edge& a, const edge& b)
{
	return a.w > b.w;
}




int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	parent.resize(n + 1);
	vector<edge> E(m);


	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		edge tmp;
		tmp.s = a; tmp.e = b; tmp.w = c;
		E.push_back(tmp);
	}

	sort(E.begin(), E.end(), comp);

	int edge_cnt = 0;
	int ans = 0;
	for (int i = m-1; i >= 0; i--) //가중치가 작은 순으로 엣지 탐색
	{
		//엣지 개수가 노드 개수 - 1이면 끝낸다
		if (edge_cnt == n - 1) break; 
		
		//s와 e가 이미 연결되어 있는 경우 간선 선택하지 않음
		if (FIND(E[i].s) == FIND(E[i].e)) continue; 

		//간선 선택
		UNION(E[i].s, E[i].e);
		ans += E[i].w;
		edge_cnt++;
	}

	cout << ans << '\n';
	return 0;
}