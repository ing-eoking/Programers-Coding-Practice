#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    int multi[2][2] = {{1, -1}, {-1, 1}};
    vector<vector<long long>> sum(2, vector<long long>(sequence.size(), 0));
    vector<long long> mini(2);
    for(int i = 0; i < sequence.size(); i++){
        for(int j = 0; j < 2; j++){
            sum[j][i] += (long long)(sequence[i]*multi[j][i%2]);
            if(i > 0) sum[j][i] += sum[j][i-1];
            answer = max(answer,sum[j][i] - mini[j]);
            mini[j] = min(mini[j], sum[j][i]);
        }
    }
    return answer;
}
