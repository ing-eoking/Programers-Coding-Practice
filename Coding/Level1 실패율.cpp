#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
bool cmp(pair<int,double> &a, pair<int, double> &b){
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    unordered_map<int, double> m;
    sort(stages.begin(), stages.end(),greater<int>());
    for(int i = 0, j = N; j > 0; j--){
        while(stages[i] > j && i < stages.size()) i++;
        m[j] = i;
        while(stages[i] == j && i < stages.size()) i++;
        
        if(0 == ((double)i - m[j])) m[j] = 0;
        else m[j] = ((double)i - m[j])/((double)i + m[j]);
        
    }
    vector<pair<int, double>> v(m.begin(), m.end());
    sort(v.begin(),v.end(), cmp);
    for(auto i : v) answer.push_back(i.first);
    
    return answer;
}
