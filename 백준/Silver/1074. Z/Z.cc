#include <iostream>

using namespace std;

int n, r, c;
int ans = 0;


void solve(int row, int col, int len)
{
	if (row == r && col == c)
	{
		cout << ans << '\n';
		return;
	}

	// r, c가 현재 사분면에 들어있는 경우
	if (r >= row && r < row + len && c >= col && c < col + len)
	{
		solve(row, col, len / 2); //1사분면
		solve(row, col + len / 2, len / 2); //2
		solve(row + len / 2, col, len / 2); //3
		solve(row + len / 2, col + len / 2, len / 2); //4
	}
	else
		ans += len * len;
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> r >> c;
	solve(0, 0, 1<<n);

	return 0;
}