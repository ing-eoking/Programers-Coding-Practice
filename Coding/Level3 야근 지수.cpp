#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    for(int i : works) pq.push(i);
    while(n > 0 && pq.top() > 0){
        pq.push(pq.top() - 1);
        pq.pop();
        n--;
    }
    long long temp = 0;
    while(!pq.empty()){
        temp = (long long) pq.top();
        answer += temp * temp;
        pq.pop();
    }
    return answer;
}
