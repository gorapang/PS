#include <string>
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

int solution(vector<int> players, int m, int k) {
    
    int answer = 0; //서버 증설 횟수
    
    int n = players.size();
    int server_cnt = 0; //현재 서버 개수
    
    vector<int> server(n);
    
    for (int i=0;i<n;i++) {
        //i:현재시각
        cout << "----------현재시각: " << i << '\n';
        int p = players[i]; //현재시각의 플레이어 수
        
        //시간 된 서버 없애기
        if (i>= k && server[i-k] != 0) {
            server_cnt -= server[i-k];
        }
        
        //서버 증설필요한 경우
        if (p >= server_cnt * m) {
            int required = p / m;
            cout << p << "명: 현재 " << server_cnt << " & 필요 " << required << '\n';
            
            int add = required - server_cnt;
            server[i] = add;
            server_cnt += add;
            answer += add;
        }
        
        cout << "증설횟수: " << answer << '\n';
        cout << "server cnt: " << server_cnt << '\n';
    }
    
    return answer;
}