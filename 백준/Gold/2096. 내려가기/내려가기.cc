#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;

int a, b, c;
int x, y, z;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num1, num2, num3;
		cin >> num1 >> num2 >> num3;
		if (i == 0)
		{
			a = num1, b = num2, c = num3;
			x = num1, y = num2, z = num3;
		}

		else
		{
			int newa, newb, newc;
			newa = max(a, b) + num1;
			newb = max(max(a, b), c) + num2;
			newc = max(b, c) + num3;

			a = newa; b = newb; c = newc;

			int newx, newy, newz;
			newx = min(x, y) + num1;
			newy = min(min(x,y), z) + num2;
			newz = min(y, z) + num3;
			
			x = newx; y = newy; z = newz;
		}

	}

	cout << max(max(a, b), c) << ' ' << min(min(x,y),z) << '\n';


	return 0;
}