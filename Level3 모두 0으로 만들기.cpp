#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


void makeTree(int step, int cur, vector<vector<int>> &tree, vector<int> &parent, priority_queue<pair<int,int>> &q){
    bool child = false;
    for(int i : tree[cur]){
        if(i != parent[cur]){
            parent[i] = cur;
            child = true;
            makeTree(step + 1, i, tree, parent, q);
        }
    }
    if(!child) q.push({step, cur});
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    long long answer = 0;
    vector<long long> ta(a.size());
    priority_queue<pair<int,int>> q;
    for(int i = 0; i < a.size(); i++) ta[i] = a[i];
    vector<vector<int>> tree(a.size());
    vector<bool> visit(a.size(), false);
    vector<int> parent(a.size());
    for(vector<int> i : edges){
        tree[i[0]].push_back(i[1]);
        tree[i[1]].push_back(i[0]);
    }
    makeTree(0, 0, tree, parent, q);
    while(!q.empty()){
        pair<int, int> p = q.top();
        q.pop();
        if(p.second == 0 || visit[p.second]) continue;
        visit[p.second] = true;
        answer += abs(ta[p.second]);
        ta[parent[p.second]] += ta[p.second];
        ta[p.second] = 0;
        q.push({p.first - 1, parent[p.second]});
    }
    if(ta[0]) return -1;
    else return answer;
}
