#include <string>
#include <vector>

using namespace std;

#define MAX(a, b) a > b ? a+1 : b+1

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer(right-left+1, 0);
    for(int i = 0; i < answer.size(); i++) answer[i] = MAX((left+i)/n, (left+i)%n);
    return answer;
}
