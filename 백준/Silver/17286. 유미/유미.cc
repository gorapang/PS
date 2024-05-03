#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[4][2];
double dist[4][4];
bool visited[4];
int ans = 987654321;

void dfs(int index, double sum, int cnt)
{
	if (cnt == 4)
	{
		ans = min(ans, (int)sum);
		return;
	}

	if (visited[index]) return;

	visited[index] = true;

	for (int i = 0; i < 4; i++)
		dfs(i, sum + dist[index][i], cnt + 1);
	
	visited[index] = false;
	return;
}


void floyd()
{
	for (int i = 0; i < 4; i++)
	{
		int x = arr[i][0];
		int y = arr[i][1];

		for (int j = i + 1; j < 4; j++)
		{
			int a = arr[j][0];
			int b = arr[j][1];
			double d = sqrt(pow(x - a, 2) + pow(y - b, 2));
			dist[i][j] = d;
			dist[j][i] = d;
		}
	}
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 2; j++)
			cin >> arr[i][j];

	floyd();
		
	dfs(0, 0.0, 0);

	cout << ans << '\n';

	return 0;
}