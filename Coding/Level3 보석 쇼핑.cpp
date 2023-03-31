#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>

using namespace std;


vector<int> solution(vector<string> gems) {
    vector<int> answer;
    set<string> t(gems.begin(), gems.end());
    map<string, int> m;
    int sz = t.size();
    int mm = gems.size()+1, j = 0;
    for(int i = 0; i < gems.size(); i++){
        while(m.size() < sz && j < gems.size()){
            m[gems[j]]++;
            j++;
        }
        if(m.size() == sz && mm > j-i){
            mm = j-i;
            answer.clear();
            answer.push_back(i+1);
            answer.push_back(j);
        }
        if(--m[gems[i]] == 0) m.erase(gems[i]);
        
    }
    return answer;
}
