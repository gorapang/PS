#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;

	vector<int> high(0);
	vector<int> low(0);

	while (1) {
		
		int n, ans;
		cin >> n;
		if (n == 0) break;

		string s1, s2;
		cin >> s1 >> s2;
		if (s2 == "high")
			high.push_back(n);
		if (s2 == "low")
			low.push_back(n);
		if (s2 == "on")
		{
			ans = n;

			bool flag = true;
			for (auto a : high)
				if (a <= ans) flag = false;
			for (auto a : low)
				if (a >= ans) flag = false;

			if (flag) cout << "Stan may be honest\n";
			else cout << "Stan is dishonest\n";

			high.clear();
			low.clear();
		}
			

	}


	return 0;
}