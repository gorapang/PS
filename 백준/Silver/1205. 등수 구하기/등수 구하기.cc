#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[10][2];


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, score, p;
	int arr[100];

	cin >> n >> score >> p;

	for (int i = 0; i < n; i++) 
		cin >> arr[i];
	


	int cnt = 0;
	int ans = 1;

	for (int i = 0; i < n; i++) 
	{
		if (score < arr[i]) 
			ans += 1;
		else if (score == arr[i]) 
			ans = ans;
		else break;
		cnt++;
	}


	if (cnt == p) ans = -1;
	if (n == 0) ans = 1;
	cout << ans << '\n';
    return 0;
}