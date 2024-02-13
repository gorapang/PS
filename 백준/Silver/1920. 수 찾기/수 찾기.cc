#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int a[100000];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	sort(a, a + N);
	
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;
		if (binary_search(a, a + N, num))
			cout << "1\n";
		else cout << "0\n";
	}

	return 0;
}