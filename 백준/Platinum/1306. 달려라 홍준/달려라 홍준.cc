#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
int arr[1000001];
vector<int> tree;

//현재 노드가 표현하는 구간의 왼쪽/오른쪽 경계, 노드의 인덱스
int set_tree(int left, int right, int node) 
{
	if (left == right) return tree[node] = arr[left]; //리프노드인 경우
	int mid = (left + right) / 2; //하위 구간으로 나누어 재귀 호출
	return tree[node] = max(set_tree(left, mid, node * 2), set_tree(mid + 1, right, node * 2 + 1));
}


//왼쪽경계, 오른쪽경계, 노드 인덱스, 노드가 표현하는 왼쪽/오른쪽 경계
int find_max(int left, int right, int node, int nodeLeft, int nodeRight) 
{
	if (nodeRight < left || right < nodeLeft) return 0; //구간 벗어남

	//현재 노드가 표현하는 구간이 찾고자 하는 구간을 완전히 포함하는 경우
	if (left <= nodeLeft && nodeRight <= right) return tree[node];

	int mid = (nodeLeft + nodeRight) / 2; //하위 구간으로 나누어 재귀 호출
	return max(find_max(left, right, node * 2, nodeLeft, mid), (find_max(left, right, node * 2 + 1, mid + 1, nodeRight)));
}

int main()
{
	cin >> N >> M;
	
	tree.resize(N * 4);


	for (int i = 0; i < N; i++) 
		cin >> arr[i];
	

	set_tree(0, N - 1, 1);


	for (int i = M - 1; i <= N - M + 1 - 1; i++) 
	{
		int left = i - M + 1;
		int right = i + M - 1;
		cout << find_max(left, right, 1, 0, N - 1) << " "; 
	}
}