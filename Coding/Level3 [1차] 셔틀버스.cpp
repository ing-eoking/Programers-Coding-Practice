#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "00:00";
    int start = 540, ret = 0;
    sort(timetable.begin(), timetable.end());
    vector<int> bustime;
    for(int i = 0; start < 1440 && i < n; i++){
        bustime.push_back(start);
        start += t;
    }
    vector<vector<int>> bus(bustime.size() + 1);
    for(string i : timetable){
        int time = i[0] * 600 + i[1] * 60 + i[3]*10 + i[4] - '0' * 671;
        int idx = lower_bound(bustime.begin(), bustime.end(), time) - bustime.begin();
        while(idx < bustime.size() && bus[idx].size() >= m) idx++;
        bus[idx].push_back(time);
    }
    bus.pop_back();
    if(bus.back().size() < m) ret = bustime.back();
    else ret = bus.back().back() - 1;
    answer[0] += (ret / 60) / 10;
    answer[1] += (ret / 60) % 10;
    answer[3] += (ret % 60) / 10;
    answer[4] += (ret % 60) % 10;
    return answer;
}
