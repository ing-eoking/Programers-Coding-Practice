#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    if(a[0] == b[0]) return a[1] > b[1];
    return a[0] < b[0];
}


int solution(vector<vector<int>> scores) {
    pair<int,int> maxp = {0, 0};
    pair<int, int> wanho = {scores[0][0], scores[0][1]};
    multiset<int> s;
    sort(scores.begin(), scores.end(), cmp);
    for(int i = scores.size() - 1; i >= 0; i--){
        if(maxp.first <= scores[i][0] || maxp.second <= scores[i][1]){
            s.insert(-scores[i][0] - scores[i][1]);
            if(maxp.second < scores[i][1]) maxp = {scores[i][0], scores[i][1]};
        }
        else if(wanho.first == scores[i][0] && wanho.second == scores[i][1]) return -1;
    }
    auto it = s.find(-wanho.first - wanho.second);
    return distance(s.begin(), it) + 1;
}
