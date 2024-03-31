#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v;
int arr[8];
bool visited[8];


void bfs(int len)
{
	if (len == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	
	for (int i = 0; i < N; i++)
	{
		if (visited[i] == false)
		{
			arr[len] = v[i];
			visited[i] = true;
			bfs(len + 1);
			visited[i] = false;
		}
	}
	
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	v.resize(N);

	for (int i = 0; i < N; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	bfs(0);

	return 0;
}

