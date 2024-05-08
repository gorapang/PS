#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string str;
	cin >> str;

	vector<char> v;
	for (int i = 0; i < str.length(); i++)
	{
		v.push_back(str[i]);
	}

	sort(v.begin(), v.end(), greater<>());

	for (int i = 0; i < v.size(); i++)
		cout << v[i];


	return 0;
}