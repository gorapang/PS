#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

string str;
char board[3][3];
int bingo_cnt = 0;
int o_bingo_cnt = 0;
int x_bingo_cnt = 0;

int x_cnt;
int o_cnt;


//O의 개수가 X보다 많을 수 없음 
void check_count()
{
	x_cnt = 0;
	o_cnt = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == 'X')
				x_cnt++;
			else if (board[i][j] == 'O')
				o_cnt++;
		}
}

bool x_win()
{
	bool flag = false;
	//가로
	for (int i = 0; i < 3; i++)
		if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X')
		{
			flag = true;
			x_bingo_cnt++;
		}

	//세로
	for (int i = 0; i < 3; i++)
		if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X')
		{
			flag = true;
			x_bingo_cnt++;
		}

	//대각선
	if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
	{
		flag = true;
		x_bingo_cnt++;
	}
	if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
	{
		flag = true;
		x_bingo_cnt++;
	}

	return flag;
}

bool o_win()
{
	bool flag = false;
	//가로
	for (int i = 0; i < 3; i++)
		if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O')
		{
			flag = true;
			o_bingo_cnt++;
		}

	//세로
	for (int i = 0; i < 3; i++)
		if (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O')
		{
			flag = true;
			o_bingo_cnt++;
		}

	//대각선
	if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
	{
		flag = true;
		o_bingo_cnt++;
	}
	if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
	{
		flag = true;
		o_bingo_cnt++;
	}

	return flag;
}

int main()
{
	/*
	최종 상태
	1) X 승리
		빙고 1개 or 2개(대각선), x_cnt == o_cnt+1
	2) O 승리
		빙고 1개, 빈칸 있음, x_cnt == o_cnt
	3) 비김
		빙고 없고, 빈칸 없고, x_cnt == o_cnt+1
		x_cnt==5, o_cnt==4
	4) 그 외 (둘 다 빙고 있음, 개수 이상함 등..)
	*/
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (1)
	{
		x_cnt = 0; o_cnt = 0;
		x_bingo_cnt = 0; o_bingo_cnt = 0;

		cin >> str;
		if (str == "end")
			return 0;

		int idx = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				board[i][j] = str[idx];
				idx++;
			}
		}

		check_count();
		if (x_cnt != o_cnt + 1 && x_cnt != o_cnt)
		{
			cout << "invalid\n";
			continue;
		}

		bool x_flag = x_win();
		bool o_flag = o_win();
		if (x_flag == true && o_flag == true)
		{
			cout << "invalid\n";
			continue;
		}

		if (x_flag)
		{
			if (x_bingo_cnt == 1 || x_bingo_cnt == 2)
				if (x_cnt == o_cnt + 1)
				{
					cout << "valid\n";
					continue;
				}
		}
		else if (o_flag)
		{
			if (o_bingo_cnt == 1)
				if (x_cnt == o_cnt)
				{
					cout << "valid\n";
					continue;
				}
		}
		else if (x_flag == false && o_flag == false)
		{
			if (x_cnt == 5 && o_cnt == 4)
			{
				cout << "valid\n";
				continue;
			}
		}

		cout << "invalid\n";
	}

	return 0;
}