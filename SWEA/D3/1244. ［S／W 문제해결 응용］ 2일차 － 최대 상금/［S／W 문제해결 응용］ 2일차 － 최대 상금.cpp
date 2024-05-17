#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int ans, n;
string str;

void dfs(int index, int depth)
{
	if (depth == n)
	{
		ans = max(ans, stoi(str));
		return;
	}

	for (int i = index; i < str.length() - 1; i++)
	{
		for (int j = i + 1; j < str.length(); j++)
		{
			swap(str[i], str[j]);
			dfs(i, depth + 1);
			swap(str[i], str[j]);
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;

	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		ans = 0;
		cin >> str >> n;
		
		if (n > str.length())
		{
			//123456
			//623451 : 1
			//653421 : 2
			//654321 : 3

			//123
			//321 : 1

			//1234
			//4231 : 1
			//4321 : 2

			//12345
			//52341
			//54321

			sort(str.begin(), str.end(), greater<int>());
			n -= (n / 2);
		}
		dfs(0, 0);
		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;
}
