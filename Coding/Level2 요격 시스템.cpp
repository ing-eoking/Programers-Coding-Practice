#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(vector<int> &a, vector <int> &b)
{return a[1] < b[1];}

int solution(vector<vector<int>> targets) {
    int answer = 0, i, j;
    sort(targets.begin(), targets.end());
    for (i = 0; i < targets.size();) {
        int back = targets[i][1];
        for(j = i + 1; j < targets.size(); j++) {
            if(targets[j][0] >= back) break;
            if(back > targets[j][1]) back = targets[j][1];
        }
        i = j;
        answer++;
    }
    
    return answer;
}
