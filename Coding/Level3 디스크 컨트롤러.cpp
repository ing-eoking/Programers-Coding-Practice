#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include<sstream>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int st = 0, sum = 0, n = jobs.size(), a = 0;
    multiset<pair<int, int>> tasks;
    sort(jobs.begin(), jobs.end(), greater<>());
    for(auto i : jobs) sum += i[1];
    while(st < sum)
    {
        while(!jobs.empty() && st >= jobs.back()[0])
        {
            tasks.insert({jobs.back()[1], jobs.back()[0]});
            jobs.pop_back();
        }
        if(!tasks.empty()){
            auto it = tasks.begin();
            st += it->first;
            a += st - it->second;
            tasks.erase(it);
        }
        else st++;
    }
    return answer = a/n;
}
