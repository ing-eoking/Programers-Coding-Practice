#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = citations.size();
    vector<int> big, small;
    sort(citations.begin(), citations.end());
    do{
        if(!big.empty()) big.clear();
        small = citations;
        while(small.back() >= answer)
        {
            big.push_back(small.back());
            small.pop_back();
        }
    }while((big.size() < answer--)&& answer >= 0);
    return ++answer;
}
