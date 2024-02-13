#include <iostream>
#include <vector>
#include <queue>
using namespace std;

char arr[50][50];

pair<int, int> beaver;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int r, c;
queue<pair<int, int>> water_q;
queue<pair<int, int>> go_q;
bool visited[50][50];
int ans = 0;

void bfs()
{
	while (!go_q.empty())
	{
		// 물 bfs
		int waterq_size = water_q.size();
		for (int i = 0; i < waterq_size; i++)
		{
			int x = water_q.front().first;
			int y = water_q.front().second;
			water_q.pop();

			for (int dir = 0; dir < 4; dir++)
			{
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx >= 0 && ny >= 0 && nx < r && ny < c && arr[nx][ny] == '.')
				{
					water_q.push(make_pair(nx, ny));
					arr[nx][ny] = '*';
				}
			}
		}

		// 고슴도치 bfs
		int goq_size = go_q.size();
		for (int i = 0; i < goq_size; i++)
		{
			int x, y;
			x = go_q.front().first;
			y = go_q.front().second;
			go_q.pop();

			for (int dir = 0; dir < 4; dir++)
			{
				int nx = x + dx[dir];
				int ny = y + dy[dir];

				if (nx == beaver.first && ny == beaver.second) // 종료조건
				{
					ans++;
					cout << ans << '\n';
					return;
				}

				if (nx >= 0 && ny >= 0 && nx < r && ny < c && arr[nx][ny] == '.')
				{

					go_q.push(make_pair(nx, ny));
					arr[nx][ny] = 'S'; //고슴도치가 이동했음을 표시

				}
			}
		}

		ans++;
	}

	cout << "KAKTUS\n"; //비버굴에 도달하지 못한 경우
	return;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'D')
			{
				beaver.first = i; beaver.second = j;
			}

			if (arr[i][j] == 'S')
			{
				go_q.push(make_pair(i, j));
			}

			if (arr[i][j] == '*')
			{
				water_q.push(make_pair(i, j));
			}
		}


	bfs();

	return 0;
}
