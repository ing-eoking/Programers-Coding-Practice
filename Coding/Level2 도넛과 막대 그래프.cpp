#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4);
    map<int, vector<int>> in, out;
    for(auto e : edges) {
        out[e[0]].push_back(e[1]);
        in[e[1]].push_back(e[0]);
    }
    for(auto o : out) 
        if(in[o.first].empty() && o.second.size() > 1) {
            answer[0] = o.first;
            break;
        }
    for(auto o : out[answer[0]]) {
        bool sin = false, dou = false;
        set<int> s({o});
        queue<int> q;
        q.push(o);
        while(!q.empty()) {
            for(int i : out[q.front()])
                if(s.insert(i).second) q.push(i);
                else if(!sin) sin = true;
                else dou = true;
            q.pop();
        }
        answer[sin + !(sin^dou)*2]++;
    }
    return answer;
}
