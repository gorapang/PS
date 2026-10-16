#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,string> a, pair<int,string> b) {
    return a.first > b.first;
}

bool cmp2(pair<int,int> a, pair<int,int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

// 장르별 많이 재생된 곡 2개씩 수록. 1. 많이재생된 장르 먼저 2. 재생수 많은 노래 먼저 3. 재생수 같으면 고유번호 낮은거 먼저
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    int n = genres.size();
    
    unordered_map<string,int> mp; // 장르별 재생횟수
    
    for (int i=0;i<n;i++) {
        string genre = genres[i];
        int play = plays[i];
        
        mp[genre]+= play;
    }
    
    vector<pair<int, string>> v; // 재생수, 장르
    for (auto a : mp) {
        string genre = a.first;
        int play = a.second;
        v.push_back(make_pair(play,genre));
    }
    
    sort(v.begin(), v.end(), cmp);

    // for (auto a: v) {
    //     cout << a.first << ' ' << a.second << '\n';
    // }
    
    for (int i=0;i<v.size();i++) {
        string genre = v[i].second; //현재장르
        
        vector<pair<int,int>> tmp; // 이 장르 내의 고유번호, 재생수
        
        for (int j=0;j<n;j++) {
            if (genres[j] == genre) {
                tmp.push_back({j, plays[j]});
            }
        }
        
        sort(tmp.begin(), tmp.end(), cmp2); // 재생수로 소팅
        
        if ((int)tmp.size() == 1) { //이 장르 곡 하나밖에 없는 경우
            answer.push_back(tmp[0].first);
        }
        else {
            answer.push_back(tmp[0].first);
            answer.push_back(tmp[1].first);
        }
        
    }
    
    return answer;
        
}