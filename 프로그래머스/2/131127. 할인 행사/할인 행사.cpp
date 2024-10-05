#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int answer = 0;

bool check(vector<string>& want, vector<int>& number, map<string,int> cnt_map)
{
    bool flag = true;
    
    for (int i = 0; i < want.size(); i++)
    {
        //want[i]가 cnt_map에 존재하지 않는 경우
        if (cnt_map.find(want[i]) == cnt_map.end())
            flag = false;
        
        //수량이 맞지 않는 경우
        else if (cnt_map[want[i]] != number[i]) 
            flag = false;
    }
    
    return flag;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) 
{
    
    for (int i = 0; i <= discount.size() - 10; i++)
    {
        map<string, int> cnt_map;
        
        for (int j = 0; j < 10; j++)
        {
            //cout << "I+J: " << i+j << '\n';
            cnt_map[discount[i+j]]++;
        }
        
        if (check(want, number, cnt_map)) 
        {
            answer++;
            //cout << "current i: " << i << '\n';
        }
            
    }
    
    return answer;
}