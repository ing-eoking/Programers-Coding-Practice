#include <string>
#include <vector>

using namespace std;

void num(const vector<int> &numbers, int n, int sum, int &answer, const int &target)
{
    if(n == numbers.size())
    {
        if(sum == target) answer++;
    }
    else{
    num(numbers, n+1, sum+numbers[n], answer, target);
    num(numbers, n+1, sum-numbers[n], answer, target);
        }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int sum = 0;
    num(numbers, 0, 0, answer, target);
    
    return answer;
}
