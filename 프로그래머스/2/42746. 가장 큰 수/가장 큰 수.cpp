#include <bits/stdc++.h>

using namespace std;

bool cmp (string a, string b) {
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    
    int n = numbers.size();
    
    vector<string> v;
    for (int i=0;i<n;i++) {
        v.push_back(to_string(numbers[i]));
    }

    sort(v.begin(), v.end(), cmp);
    if (v[0] == "0") return "0";

    string answer = "";
    for (string s : v) {
        answer += s;
    }
    
    return answer;
}