#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

map<int, vector<pair<int, int>>> pt;

int calcWait(int type, int n) {
    vector<int> v(n, 0);
    multiset<int> s(v.begin(), v.end());
    int wait = 0, cur, st;
    for(auto i : pt[type]) {
        st = cur = *s.begin();
        if(i.first < cur) 
            wait += cur - i.first;
        else st = i.first;
        s.erase(s.begin());
        s.insert(st + i.second);
    }
    return wait;
}

int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = 0;
    vector<vector<int>> cost(k, vector<int>(n + 2, -1));
    map<int, int> mt;
    for(auto i : reqs) {
        pt[i[2] - 1].push_back({i[0], i[1]});
        mt[i[2] - 1] = 1;
    }
    int total = n - k, max_mt, max_ty;
    while(total-- > 0) {
        max_mt = -1; max_ty = -1;
        for(auto i : mt) {
            if(cost[i.first][i.second] < 0) 
                cost[i.first][i.second] = calcWait(i.first, i.second);
            if(cost[i.first][i.second + 1] < 0)
                cost[i.first][i.second + 1] = calcWait(i.first, i.second + 1);
            int c = cost[i.first][i.second] - cost[i.first][i.second + 1];
            if(max_mt < c) {
                max_mt = c;
                max_ty = i.first;
            }
        }
        mt[max_ty]++;
    }
    for(auto i : mt){
        if(cost[i.first][i.second] < 0) 
            cost[i.first][i.second] = calcWait(i.first, i.second);
        answer += cost[i.first][i.second];
    }
    return answer;
}
