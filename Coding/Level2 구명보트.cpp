#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int st = 0;
    sort(people.begin(), people.end());
    while(st<people.size()){
        if(people.back()+ people[st] <= limit) st++;
        answer++;
        people.pop_back();
    }
    return answer;
}
