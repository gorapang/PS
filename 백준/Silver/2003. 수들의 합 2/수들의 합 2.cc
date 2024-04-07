#include <iostream>
using namespace std;

int arr[10001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) 
		cin >> arr[i];

	int sum = 0, s = 0, e = 0, ans = 0;

	while (e <= N) 
	{
		if (sum > M) 
			sum -= arr[s++];
		else if (sum == M) {
			ans++;
			sum -= arr[s++];
		}
		else
			sum += arr[e++];
	}
	cout << ans;
}