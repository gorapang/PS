#include <string>
#include <vector>
#include <queue>
using namespace std;

bool canChange(string a, string b) {
    int diff = 0;
    for (int i=0;i<a.size();i++) {
        if (a[i] != b[i]) diff++;
    }
    if (diff == 1) return true;
    else return false;
    
}

int solution(string begin, string target, vector<string> words) {

    
    vector<bool> visited(words.size(), false);
    queue<pair<string,int>> q;
    
    q.push({begin, 0});
    
    while (!q.empty()) {
        string cur = q.front().first;
        int step = q.front().second;
        q.pop();
        
        if (cur == target) {
            return step;
        }
        
        for (int i=0; i<words.size(); i++) {
            if (!visited[i] && canChange(cur, words[i])) {
                visited[i] = true;
                q.push({words[i], step+1});
            }
        }
    }
    
    return 0;
}