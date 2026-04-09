#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define INF 987654321
using namespace std;

vector<vector<int>> graph;

int bfs(int start, int a, int b, int n) {
    int cnt = 0;
    
    vector<bool> visited(n, false);
    queue<int> q;
    
    visited[start] = true;
    q.push(start);
    cnt++;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int next : graph[cur]) {
            if (cur == a && next == b) continue;
            if (cur == b && next == a) continue;
            
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
                cnt++;
            }
        }
        
    }
    
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = INF;
    
    graph.resize(n+1);
    
    for (int i=0;i<wires.size();i++) {
        int a = wires[i][0];
        int b = wires[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    //끊기
    for (int i=0;i<wires.size();i++) {
        int a= wires[i][0];
        int b= wires[i][1];
        
        int cnt = bfs(1, a, b, n);
        cout << cnt << '\n';
        
        int cnt2 = n-cnt;
        int diff = abs(cnt-cnt2);
        answer = min(answer, diff);
    }
    
    return answer;
}