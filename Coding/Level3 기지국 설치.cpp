#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int solution(int n, vector<int> stations, int w)
{
    int answer = 0, beg = 0;
    vector<pair<int, int>> stat;
    stat.push_back({stations[0] - 1 - w, stations[0] - 1 + w});
    if(stat[0].first < 0) stat[0].first = 0;
    if(stat[0].second >= n) stat[0].second = n - 1;
    for(int i = 1; i < stations.size(); i++){
        int st = stations[i] - 1 - w, ed = stations[i] - 1 + w;
        if(ed >= n) ed = n -1;
        if(stat.back().second + 1 >= st) stat[stat.size() - 1].second = ed;
        else stat.push_back({st, ed});
    }
    int st = 0, ed = 0;
    for(auto i : stat){
        if(st >= n) break;
        ed = i.first - 1;
        if(st <= ed) answer += ceil((double)(ed - st + 1) / (w*2 + 1));
        st = i.second + 1;
    }
    if(stat.back().second < n - 1){
        st = stat.back().second + 1;
        ed = n - 1;
        answer += ceil((double)(ed - st + 1)/ (w*2 +1));
    }
    return answer;
}
