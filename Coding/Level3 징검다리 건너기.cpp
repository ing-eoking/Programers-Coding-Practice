#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 200000000;
    deque<pair<int, int>> q;
    for(int i = 0; i < stones.size(); i++){
        while(!q.empty() && q.back().first < stones[i]) q.pop_back();
        while(!q.empty() && q.front().second <= i - k) q.pop_front();
        q.push_back({stones[i],i});
        if(i >= k - 1 && answer > q.front().first) answer = q.front().first;
    }
    return answer;
}
