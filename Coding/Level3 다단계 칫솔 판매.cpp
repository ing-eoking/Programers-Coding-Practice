#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

#define GR pair<int, string>

bool cmp(pair<string, GR> &a, pair<string, GR> &b){
    return a.second.first > b.second.first;
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    unordered_map<string, string> m;
    unordered_map<string, int> profit;
    for(int i = 0; i < enroll.size(); i++) m[enroll[i]] = referral[i];
    for(int i = 0; i < seller.size(); i++){
        int svc = amount[i]*10;
        profit[seller[i]] += amount[i]*100 - svc;
        string giv = m[seller[i]];
        while(svc > 0 && giv != ""){
            profit[giv] += svc;
            svc = svc/10;
            profit[giv] -= svc;
            giv = m[giv];
        }
    }
    for(auto i : enroll) answer.push_back(profit[i]);
    
    
    return answer;
}
