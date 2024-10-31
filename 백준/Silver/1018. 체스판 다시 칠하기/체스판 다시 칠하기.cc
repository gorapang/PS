#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int m, n;
	scanf("%d %d", &n, &m);

	char arr[50][50];
	for (int i = 0; i < n; i++)
	{
		scanf("%s", arr[i]);
	}

	int cnt = 0; int min = 64;
	for (int i = 0; i < n - 7; i++)
	{
		for (int j = 0; j < m - 7; j++)
		{

			for (int row = i; row <= i + 7; row++)
			{
				for (int col = j; col <= j + 7; col++)
				{
					if ((row + col) % 2 == 0)
					{
						if (arr[row][col] == 'B')
							cnt++;
					}
					else
					{
						if (arr[row][col] == 'W')
							cnt++;
					}
				}
			}

			if (cnt > 32)
				cnt = 64 - cnt;
			if (cnt < min)
				min = cnt;
			cnt = 0;
		}
	}
	printf("%d", min);
	return 0;
}