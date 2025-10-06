#include <string>
#include <set>
#include <iostream>
#include <vector>
using namespace std;

//vector<pair<int,int>> v;


int solution(string dirs) {
    int answer = 0;
    int n = dirs.length();
    
    int x = 0;
    int y = 0;
    //v.push_back(make_pair(x,y));
    set<vector<int>> st;
    // set<pair<int,int>> st;
    // pair<pair<int,int>, pair<int,int>> p;
    
    for (int i=0;i<n;i++) {
        char cmd = dirs[i];
        int nx, ny;
        vector<int> tmp;
        //cmd에 따라 다음 좌표 구하기. 단, 좌표범위 벗어나는 경우 무시
        if (cmd == 'U') {
            nx = x;
            ny = y+1;
            
            tmp.push_back(nx);
            tmp.push_back(ny); //더 위에있는 좌표를 먼저 넣기
            tmp.push_back(x);
            tmp.push_back(y);
        }
        else if (cmd == 'D') {
            nx = x;
            ny = y-1;
            tmp.push_back(x);
            tmp.push_back(y);
            tmp.push_back(nx);
            tmp.push_back(ny);
        }
        else if (cmd == 'R') {
            nx = x+1;
            ny = y;
            tmp.push_back(x);
            tmp.push_back(y);
            tmp.push_back(nx);
            tmp.push_back(ny);
        }
        else {
            nx = x-1;
            ny = y;
            tmp.push_back(nx);
            tmp.push_back(ny); // 더 왼쪽에 있는 좌표를 먼저넣기
            tmp.push_back(x);
            tmp.push_back(y);
        }
        
        if (nx < -5 || nx > 5 || ny < -5 || ny > 5) continue;
        st.insert(tmp);

        x= nx;
        y= ny;
        //cout << "x: " << x << " | y: " << y << '\n';
    }
    
    int ans = 0;
    for (vector<int> v: st) {
        // cout << "x: " << v[0] << " | y: " << v[1] << " |nx: " << v[2] << "| ny: " << v[3] << '\n';
        ans++;
    }
    
    return ans;
}