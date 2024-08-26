#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, q;
vector<long long> tree;

void set_tree(int i)
{
	while (i != 1)
	{
		tree[i / 2] += tree[i];
		i--;
	}
}

void update_val(int index, int value)
{
	long long diff = value - tree[index];
	while (index > 0)
	{
		tree[index] += diff;
		index /= 2;
	}
}

long long get_sum(int s, int e)
{
	long long sum = 0;

	while (s <= e)
	{
		if (s % 2 == 1)
		{
			sum += tree[s];
			s++;
		}

		if (e % 2 == 0)
		{
			sum += tree[e];
			e--;
		}

		s /= 2;
		e /= 2;
	}

	return sum;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> q;

	int tree_height = ceil(log2(n));
	int tree_size = pow(2, tree_height + 1);
	tree.resize(tree_size);

	int left_start_index = tree_size / 2 - 1;

	for (int i = 1; i <= n; i++)
		cin >> tree[left_start_index + i];

	set_tree(tree_size - 1);

	for (int i = 0; i < q; i++)
	{
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		if (x > y) swap(x, y);

		int s = left_start_index + x;
		int e = left_start_index + y;

		cout << get_sum(s, e) << '\n';

		update_val(left_start_index + a, b);
	}

	return 0;
}