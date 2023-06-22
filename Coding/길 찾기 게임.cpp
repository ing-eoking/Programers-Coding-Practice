#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> child(10001, vector<int>(2,0)), answer(2);

bool cmp(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b){
    if(a.second.second == b.second.second) return a.second.first < b.second.first;
    return a.second.second > b.second.second;
}
void pre(int cur){
    answer[0].push_back(cur);
    if(child[cur][0]) pre(child[cur][0]);
    if(child[cur][1]) pre(child[cur][1]);
}
void post(int cur){
    if(child[cur][0]) post(child[cur][0]);
    if(child[cur][1]) post(child[cur][1]);
    answer[1].push_back(cur);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<pair<int, pair<int, int>>> tree;
    int height = 0;
    for(int i = 1; i <= nodeinfo.size(); i++) tree.push_back({i, {nodeinfo[i-1][0],nodeinfo[i-1][1]}});
    sort(tree.begin(), tree.end(), cmp);
    for(int i = 1; i < tree.size(); i++){
        int par = tree[0].first;
        bool idx = nodeinfo[par-1][0] < tree[i].second.first;
        while(child[par][idx] > 0){
            par = child[par][idx];
            idx = nodeinfo[par-1][0] < tree[i].second.first;
        }
        child[par][idx] = tree[i].first;
    }
    pre(tree[0].first);
    post(tree[0].first);
    return answer;
}
