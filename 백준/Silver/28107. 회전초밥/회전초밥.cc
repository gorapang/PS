#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue<int> q[200001]; //q[i]: 스시i를 먹고싶은 사람들

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;

	vector<int> cnt(N);
	vector<int> sushi(M);

	for (int i = 0; i < N; i++)
	{
		int k;
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			int s;
			cin >> s;
			q[s].push(i);
		}
	}
	
	for (int i = 0; i < M; i++)
		cin >> sushi[i];

	for (int i = 0; i < M; i++)
	{
		if (!q[sushi[i]].empty())
		{
			cnt[q[sushi[i]].front()]++;
			q[sushi[i]].pop();
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << cnt[i] << ' ';
	}

	return 0;
}