#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int N;
int max_length;
vector<int> arr;
vector<int> candidate;
vector<int> loc;
vector<int> ans;

int binary_search(int l, int r, int now)
{
	while (l < r) 
	{
		int mid = (l + r) / 2;

		if (candidate[mid] < now)
			l = mid + 1;
		else
			r = mid;
	}

	return l;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;

	arr.resize(N + 1);
	candidate.resize(N + 1);
	loc.resize(N + 1);
	ans.resize(N + 1);

	for (int i = 1; i <= N; i++)
		cin >> arr[i];



	candidate[1] = arr[1];
	max_length++;
	loc[1] = 1; //loc[i]=n; arr[i]가 candidate[n]에 들어감


	for (int i = 2; i <= N; i++)
	{
		if (candidate[max_length] < arr[i])
		{
			max_length++;
			candidate[max_length] = arr[i];
			loc[i] = max_length;
		}
		else
		{
			int index = binary_search(1, max_length, arr[i]);
			candidate[index] = arr[i];
			loc[i] = index;
		}
	}

	int index = max_length;

	for (int i = N; i >= 1; i--)
	{
		if (loc[i] == index)
		{
			ans[index] = arr[i];
			index--;
		}
	}

	cout << max_length << '\n';
	for (int i = 1; i <= max_length; i++)
		cout << ans[i] << ' ';
	cout << '\n';

	return 0;
}