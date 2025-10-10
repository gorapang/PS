#include <string>
#include <vector>
#include <set>
#include <tuple>
using namespace std;

int best_answer = 987654321;
int n_limit, m_limit;
vector<vector<int>> information;
int items_cnt;

set<tuple<int,int,int>> visited; //i,a_sum,b_sum 상태의 방문여부 저장

void dfs(int i, int a_sum, int b_sum) {
    if (a_sum >= n_limit || b_sum >= m_limit) return;  //둘중 한명이라도 잡히는 경우

    //같은 상태를 중복 탐색하는 경우 방지
    auto a = make_tuple(i,a_sum,b_sum);
    if (visited.find(a) != visited.end()) {
        return;
    }
    visited.insert(a);
        
    if (best_answer <= a_sum) return; // 이미 최소값보다 크면 볼 필요 없음

    if (i == items_cnt) { //모든 물건 훔쳤을때
        best_answer = min(best_answer, a_sum);
        return;
    }
    
    int a_cost = information[i][0];
    int b_cost = information[i][1];
    
    dfs(i+1, a_sum + a_cost, b_sum); //A도둑이 훔치는 경우
    dfs(i+1, a_sum, b_sum + b_cost); //B도둑이 훔치는 경우
    
}

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    
    information = info;
    n_limit = n;
    m_limit = m;
    items_cnt = info.size();
    
    dfs(0,0,0);
    
    if (best_answer >= n_limit) return -1;
    return best_answer;
}