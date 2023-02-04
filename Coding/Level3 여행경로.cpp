#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int sz = 10000;
vector<string> gl;
bool tf = false;

void dfs(string des,map<string, multiset<string>> &m, int num)
{
    if(num == sz) {
        gl[num-1] = des;
        tf = true;
    }
    for(auto i : m[des])
    {
        m[des].erase(m[des].find(i));
        dfs(i, m, num+1);
        if(tf) {
            gl[num-1]= des;
            break;}
        m[des].insert(i);
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    map<string, multiset<string>> m;
    sz = tickets.size()+1;
    gl = vector<string>(sz);
    for(auto i : tickets){
        m[i[0]].insert(i[1]);
    }
    dfs("ICN",m, 1);
    return answer = gl;
}
