#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

struct Student 
{
    string name;
    int popularity;

    bool operator<(const Student& other) const 
    {
        if (popularity == other.popularity)
            return name < other.name;
        return popularity > other.popularity;
    }
};

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    cin.ignore();

    vector<string> S;
    map<string, int> P;


    string input;
    getline(cin, input);
    size_t pos = 0;
    while ((pos = input.find(' ')) != string::npos) 
    {
        S.push_back(input.substr(0, pos));
        P[input.substr(0, pos)] = 0;
        input.erase(0, pos + 1);
    }
    S.push_back(input);
    P[input] = 0;


    for (int i = 0; i < n; ++i) 
    {
        getline(cin, input);
        size_t pos = 0;
        while ((pos = input.find(' ')) != string::npos) 
        {
            string s = input.substr(0, pos);
            P[s]++;
            input.erase(0, pos + 1);
        }
        P[input]++; 
    }

    vector<Student> res;
    for (string& student : S) 
        res.push_back({ student, P[student] });
 
    sort(res.begin(), res.end());


    for (auto& student : res) 
    {
        cout << student.name << " " << student.popularity << '\n';
    }

    return 0;
}
