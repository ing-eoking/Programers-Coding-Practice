#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
bool cmp(const pair<string, pair<int, set<pair<int, int>>>> & a,
        const pair<string, pair<int, set<pair<int, int>>>> &b)
{
    return a.second.first < b.second.first;
}
bool cmp2(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, pair<int, set<pair<int, int>> >> m;
    set <int> s;
    for(int i = 0; i < genres.size(); i++)
    {
        m[genres[i]].first += plays[i];
        m[genres[i]].second.insert({plays[i], i});
    }
    vector<pair<string, pair<int, set<pair<int, int>>>>> v(m.begin(), m.end());
    sort(v.begin(),v.end(),cmp);
    m.clear();
    while(!v.empty())
    {
        vector<pair<int,int>> t(v.back().second.second.begin(), v.back().second.second.end());
        sort(t.begin(), t.end(),cmp2);
        for(int i = 0; (i<2)&& !t.empty(); i++)
        {
            if(s.find(t.back().second) == s.end()) {
                s.insert(t.back().second);
                answer.push_back(t.back().second);
            }
            t.pop_back();
        }
        v.pop_back();
        //if(answer.size() == 4) break;
    }
    
    return answer;
}
