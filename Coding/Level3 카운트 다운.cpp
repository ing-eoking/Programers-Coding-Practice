#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int target) {
    vector<int> answer;
    vector<pair<int, int>> score(target+1, {100001, 0});
    int cur = 0;
    score[0] = {0,0};
    queue<int> q;
    pair<int, int> temp = score[0];
    q.push(0);
    while(!q.empty()){
        cur = q.front();
        q.pop();
        if(cur == target) break;
        for(int i = 1; i <= 3; i++){
            for(int j = 1; j <= 20; j++){
                if(cur + i*j > target) break;
                if(score[cur + i*j].first > score[cur].first + 1){
                    score[cur + i*j] = {score[cur].first + 1, score[cur].second + (int)(i == 1)};
                    q.push(cur+i*j);
                }
                if(score[cur + i*j].first == score[cur].first + 1 
                   && score[cur + i*j].second < score[cur].second + (int)(i==1)){
                    score[cur + i*j].second = score[cur].second + (int)(i == 1);
                    q.push(cur + i*j);
                }
            }
        }
        if(cur + 50 <= target){
            if(score[cur + 50].first > score[cur].first + 1){
                score[cur + 50] = {score[cur].first + 1, score[cur].second+1};
                q.push(cur + 50);
            }
            if(score[cur + 50].first == score[cur].first + 1
              && score[cur + 50].second < score[cur].second + 1){
                score[cur + 50].second = score[cur].second + 1;
                q.push(cur + 50);
            }
        }
        
    }
    answer.push_back(score[target].first);
    answer.push_back(score[target].second);
    return answer;
}
