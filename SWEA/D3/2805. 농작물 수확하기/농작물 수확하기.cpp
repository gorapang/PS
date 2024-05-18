#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int n;
int farm[50][50];

int solve(int farm[50][50], int n)
{
	int ans = 0;
	int tmp = n / 2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0+tmp; j < n-tmp; j++)
		{
			ans += farm[i][j];
		}

		if (i < n / 2)tmp--;
		else tmp++;
	}

	return ans;
}

int main(int argc, char** argv)
{
	int test_case;

	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				char ch;
				cin >> ch;
				farm[i][j] = ch - '0';
			}
				

		int ans = solve(farm, n);
		cout << '#' << test_case << ' ' << ans << '\n';


	}
	return 0;
}