#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

static int N, M;
static vector <vector<int>> tree;
static vector<int> depth;
static int kmax;
static int parent[21][100001];
static vector<bool> visited;

int excuteLCA(int a, int b);
void BFS(int node);
void BFS(int node);

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    tree.resize(N + 1);
    depth.resize(N + 1);
    visited.resize(N + 1);

    for (int i = 0; i < N - 1; i++) { // A인접리스트에 그래프 데이터 저장
        int s, e;
        cin >> s >> e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }


    kmax = ceil(log2(N));

    BFS(1); // depth를 BFS를 통하여 구하기

    for (int k = 1; k <= kmax; k++) {   // 점화식을 이용한 parent 배열 채우기
        for (int n = 1; n <= N; n++) {
            parent[k][n] = parent[k - 1][parent[k - 1][n]];
        }
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        // 공통 조상을 구할 두 노드
        int a, b;

        cin >> a >> b;
        int LCA = excuteLCA(a, b);
        cout << LCA << "\n";
    }
}


int excuteLCA(int a, int b) 
{
    if (depth[a] > depth[b]) //더 깊이가 깊은 depth가 b가 되도록 변경해주기
        swap(a, b);
    

    for (int k = kmax; k >= 0; k--) // depth 빠르게 맞춰주기
    {
        if (pow(2, k) <= depth[b] - depth[a]) 
            if (depth[a] <= depth[parent[k][b]]) 
                b = parent[k][b];
    }

    for (int k = kmax; k >= 0 && a != b; k--) // 조상 빠르게 찾기
    { 
        if (parent[k][a] != parent[k][b]) {
            a = parent[k][a];
            b = parent[k][b];
        }
    }
    int LCA = a;
    if (a != b)
        LCA = parent[0][LCA];
    return LCA;
}


void BFS(int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;

    int qsize;
    int level = 1;

    while (!q.empty())
    {
        qsize = q.size();

        for (int i = 0; i < qsize; i++)
        {
            int now = q.front();
            q.pop();

            for (int next : tree[now])
            {
                if (!visited[next])
                {
                    q.push(next);
                    visited[next] = true;
                    parent[0][next] = now; // 부모 노드 저장
                    depth[next] = level; //노드 depth 저장
                }
            }
        }

        level++;
    }
}
