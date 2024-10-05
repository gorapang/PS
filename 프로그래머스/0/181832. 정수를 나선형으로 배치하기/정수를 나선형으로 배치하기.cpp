#include <string>
#include <vector>
#include <iostream>
using namespace std;


int dx[] = {0,1,0,-1}; 
int dy[] = {1,0,-1,0};
int dir = 0; //우 하 좌 상

vector<vector<int>> solution(int n) 
{
    vector<vector<int>> answer;
    answer.resize(n, vector<int>(n));
    
    vector<vector<bool>> visited;
    visited.resize(n, vector<bool>(n, false));
    
    
    int num = 1;
    int x = 0, y = 0;
    dir = 0; //오른쪽
    
    for (int i=0; i<n*n; i++)
    {
        if (num > n*n) break;
        
        answer[x][y] = num;
        visited[x][y] = true;
        
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx >= n || nx < 0 || ny >= n || ny < 0 || visited[nx][ny]) 
        {
            dir = (dir + 1) % 4;
            nx = x + dx[dir];
            ny = y + dy[dir];
        }
        
        x = nx;
        y = ny;
        num++;
    }
    
    return answer;
}