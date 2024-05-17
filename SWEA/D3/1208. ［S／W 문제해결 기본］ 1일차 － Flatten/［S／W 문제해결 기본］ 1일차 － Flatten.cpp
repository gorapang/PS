#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int ans, n;
string str;
bool flag;

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
	T = 10;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int dump;
		cin >> dump;
		
		vector<int> box(100);
		for (int i = 0; i < 100; i++)
			cin >> box[i];

		while (dump--)
		{
			sort(box.begin(), box.end());

			box[99]--;
			box[0]++;

			if (box[99] == box[0]) break;
			sort(box.begin(), box.end());
		}
		
		cout << '#' << test_case << ' ' << box[99] - box[0] << '\n';
		
	}
	return 0;
}