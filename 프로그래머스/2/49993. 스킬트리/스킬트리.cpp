#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

bool check_exist(string skill, char c) {
    int len = skill.length();
    for (int i=0;i<len;i++) {
        char cur = skill[i];
        if (cur == c) return true;
    }
    
    return false;
}


bool check(string skill, char c, 
unordered_map<char, bool> mp)
{
    int len = skill.length();
    for (int i=0;i<len;i++) {
        char cur = skill[i];
        if (cur != c) {
            if (mp[cur] == false) return false;
        }
        if (cur == c) break;
    }
    
    return true;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = -1;
    
    
    int cnt = 0;
    
    int n = skill_trees.size();
    for (int i=0; i<n; i++) {
        string skilltree = skill_trees[i];
        cout << "스킬트리: " << skilltree << '\n';
        int len = skill_trees[i].length();
        
        
        bool flag = true; //이번 스킬트리의 가능여부      
        unordered_map<char, bool> mp;
        
        for (int j=0;j<len;j++) {
            char c = skilltree[j];
            mp[c] = true;
            
            //선행스킬에 존재하는지먼저 확인
            if (check_exist(skill, c)) { 
                if (check(skill,c,mp)) {
                    cout << "현재스킬 " << c << " 가능" << '\n';
                }
                else {
                    cout << "현재스킬 " << c << " 불가능\n";
                    flag = false;
                    break;
                }               
            } 

        }
        
        if (flag==true) {
            cnt++; 
            cout << "이번 스킬트리는 가능. cnt: " << cnt << '\n';
        }
        
    }
    
    return cnt;
}