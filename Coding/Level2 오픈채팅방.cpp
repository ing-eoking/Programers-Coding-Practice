#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    for(auto i : record){
        stringstream temp(i);
        temp.str(i);
        vector<string> v;
        string nt;
        while(temp >> nt) v.push_back(nt);
        if(v[0].compare("Enter") == 0 || v[0].compare("Change") == 0)
            m[v[1]] = v[2];
    }
    for(auto i : record){
         stringstream temp(i);
        temp.str(i);
        vector<string> v;
        string nt;
        while(temp >> nt) v.push_back(nt);
        if(v[0].compare("Enter") == 0){
            answer.push_back(m[v[1]]+"님이 들어왔습니다.");
        }
        if(v[0].compare("Leave") == 0){
            answer.push_back(m[v[1]]+"님이 나갔습니다.");
        }
    }
    return answer;
}
