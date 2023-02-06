#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    map<int, set<int>> m, d;
    for(auto i : edge)
    {
        m[i[0]].insert(i[1]);
        m[i[1]].insert(i[0]);
    }
    d[0].insert(1);
    for(int i = 0; i < n; i++)
    {
        for(auto k : d[i])
            for(auto l : m[k])
            {
                if(d[i].find(l) == d[i].end())
                    d[i+1].insert(l);
                m[l].erase(k);
            }
        if(d[i+1].empty())
        {
            d.erase(i+1);
            break;
        }
        
    }
    return answer = (--d.end())->second.size();
}
