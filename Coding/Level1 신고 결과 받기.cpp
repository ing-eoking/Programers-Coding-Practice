#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size());
    map<string, set<string>> m;
    map<string, int> c;
    for(auto i: id_list) c[i] = 0;
    string t1, t2;
    for(auto i:report){
        stringstream temp(i);
        temp.str(i);
        temp >> t1;
        temp >> t2;
        m[t2].insert(t1);
    }
    for(auto i:m){
        //find(id_list.begin(), id_list.end(), 1) - id_list.begin()
        if(i.second.size() >= k) {
            for(auto j:i.second){
                c[j]++;
            }
        }
        
    }
    for(int i = 0; i < id_list.size(); i++){
        answer[i] = c[id_list[i]];
    }
    
    return answer;
}
