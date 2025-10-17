#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

unordered_map<string, int> mp;

char arr[5] = {'A','E','I','O','U'};
string str ="";
int idx = 1;

void make_str(string str) {
    if (str.size() > 5) return;
    
    if (!str.empty()) {
        mp[str] = idx;
        idx++;
    }
    
    for (int i=0;i<5;i++) {
        make_str(str + arr[i]);
    }
}

int solution(string word) {
    int answer = 0;
    
    string str = "";
    make_str(str);
    
    answer = mp[word];
    
    return answer;
}