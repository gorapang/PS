#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int n;
long long ans = 0;

int count_element(vector<long long> v, int num)
{
	int tmp = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == num)
			tmp++;
	}
	return tmp;
}

long long count(vector<long long> A, vector<long long> B, vector<long long> C, vector<long long> D)
{
	vector<long long> v, w;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			v.push_back(A[i] + B[j]);
			w.push_back(C[i] + D[j]);
		}
	}

	std::sort(v.begin(), v.end());
	std::sort(w.begin(), w.end());

	long long start = 0, end = v.size() - 1; //2 pointer
	long long result = 0, sum;
	while (start < v.size() && end >= 0) {
		sum = v[start] + w[end];
		if (sum > 0) end--;
		else if (sum == 0) {
			long long ab = 1, cd = 1;
			while (start < v.size() - 1 && v[start] == v[start + 1]) {
				start++;
				ab++;
			}
			while (end > 0 && w[end] == w[end - 1]) {
				end--;
				cd++;
			}
			result += ab * cd;
			start++;
		}
		else start++;
	}

	return result;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	vector<long long> A(n);
	vector<long long> B(n);
	vector<long long> C(n);
	vector<long long> D(n);
	for (int i = 0; i < n; i++)
	{
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}
	ans += count(A, B, C, D);

	cout << ans << '\n';
	return 0;
}