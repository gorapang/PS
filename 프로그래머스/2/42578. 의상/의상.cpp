#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    unordered_map<string, int> mp;
    
    for (vector<string> v : clothes) {
        string name = v[0];
        string type = v[1];
        mp[type]++;    
    }
    
    int cnt = 1;
    for (pair<string,int> p: mp) {
        cout << "type: " << p.first << " | cnt: " << p.second << '\n';
        cnt = cnt * (p.second+1);
    }
    
    answer = cnt -1;
    return answer;
}