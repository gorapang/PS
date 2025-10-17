#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

vector<int> diff; //나눈 두 전력망의 송전탑 개수 차이
vector<vector<int>> graph;

int bfs(int start, int n, int a, int b) {
    vector<bool> visited(n+1);
    int count = 1; //송전탑개수
    queue<int> q;
    q.push(start);
    visited[start] = true;
    

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int next: graph[cur]) {
            if (cur == a && next == b) continue;
            if (cur == b && next == a) continue;
            
            if (!visited[next]) {
                count++;
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return count;
}


int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    
    graph.resize(n+1);
    for (int i=0;i<n-1;i++) {
        int a = wires[i][0]; 
        int b = wires[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    
    int ans = 987654321;
    
    for (int i=0;i<n-1;i++) {
        // i번째 와이어가 없다고 가정
        int a = wires[i][0];
        int b = wires[i][1];
        int cnt = bfs(1, n, a, b);
        
        int d = abs((n-cnt) - cnt);
        if (d < ans) ans = d;
        
    }
    
    
    return ans;
}