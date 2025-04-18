#include <iostream>
#include <string>
#include <set>
using namespace std;

char arr[5][5];
set<string> s;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

void dfs(int x, int y, string path, int depth)
{
	if (depth == 5)
	{
		s.insert(path);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5)
		{
			dfs(nx, ny, path + arr[nx][ny], depth + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++) {
			dfs(i, j, to_string(arr[i][j]), 0);
		}
	}

	cout << s.size() << '\n';

	return 0;
}