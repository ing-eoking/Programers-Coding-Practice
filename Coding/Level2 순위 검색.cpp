#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    map<string, vector<int>> m;
    int score;
    for(string i : info){
        istringstream ss(i);
        int s;
        vector<vector<string>> x(4,vector<string>(2,"-"));
        for(int a = 0; a < 4; a++) ss >> x[a][0];
        ss >> s;
        for(string a : x[0])
            for(string b : x[1])
                for(string c : x[2])
                    for(string d : x[3])
                        m[a+b+c+d].push_back(s);
    }
    for(auto &i : m) sort(i.second.begin(), i.second.end());
    for(string i : query){
        istringstream ss(i);
        vector<string> x;
        string key = "";
        int s;
        for(int a = 0; a < 7; a++){
            string temp;
            ss >> temp;
            if(temp != "and") key += temp;
        }
        ss >> s;
        answer.push_back((int)(m[key].end() - lower_bound(m[key].begin(), m[key].end(),s)));
        
    }
    return answer;
}
