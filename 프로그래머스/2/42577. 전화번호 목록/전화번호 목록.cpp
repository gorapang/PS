#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    
    int n= phone_book.size();
    
    for (int i=0;i<n-1;i++) {
        string s1 = phone_book[i];
        string s2 = phone_book[i+1];
        
        int s1_size = s1.length();
        if (s2.substr(0, s1_size) == s1) answer = false;
    }
    
    return answer;
}