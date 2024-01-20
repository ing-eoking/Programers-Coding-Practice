#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<vector<int>> dice) {
    int N = dice.size();
    vector<int> answer;
    vector<map<int, int>> stat(N);
    vector<int> nums, comb, ans;
    int max = -1;
    for(int i = 0; i < N; i++) {
        nums.push_back(i);
        if(i < N/2) comb.push_back(0);
        else comb.push_back(1);
        for(int j = 0; j < 6; j++) 
            stat[i][dice[i][j]]++;
    }
    
    do{
        vector<map<int, int>> v(2);
        for(int i = 0; i < N; i++) {
            if(v[comb[i]].empty()) {
                v[comb[i]] = stat[i];
            }
            else {
                map<int, int> m;
                for(auto j : v[comb[i]]){
                    for(auto k : stat[i]){
                        m[j.first + k.first] += j.second * k.second;
                    }
                }
                v[comb[i]] = m;
            }
        }
        int win = 0;
        for(auto i : v[0]) {
            for(auto j : v[1]){
                if(i.first <= j.first) break;
                else win += i.second * j.second;
            }
        }
        if(win > max){
            max = win;
            ans = comb;
        }

	}while(next_permutation(comb.begin(), comb.end()));
    for(int i = 0; i < N; i++) if(!ans[i]) answer.push_back(i+1);
    return answer;
}
