#include <string>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

set<int> st;
vector<bool> visited;

bool is_prime(int num) {
    if (num < 2) return false;
    
    for (int i=2; i<=sqrt(num); i++) {
        if (num%i==0) return false;
    }
    
    return true;
}

void dfs(string cur, string numbers) {
    if (!cur.empty()) {
        st.insert(stoi(cur));        
    }
    
    for (int i=0; i<numbers.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(cur+numbers[i], numbers);
            visited[i] = false;
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    
    int n = numbers.size();
    visited.resize(n);
    
    dfs("", numbers);
    
    for (int a : st) {
        if (is_prime(a)) answer++;
    }
    
    return answer;
}