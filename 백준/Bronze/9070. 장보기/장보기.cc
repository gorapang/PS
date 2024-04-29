#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N;
		cin >> N;
		int ans = 0;
		double minval = 100001;
		for (int i = 0; i < N; i++)
		{
			double w, c;
			cin >> w >> c;
			
			if (c / w < minval)
			{
				minval = c / w;
				ans = c;
			}
			else if (c / w == minval && c < ans)
				ans = c;
		}
		cout << ans << '\n';
	}

	return 0;
}