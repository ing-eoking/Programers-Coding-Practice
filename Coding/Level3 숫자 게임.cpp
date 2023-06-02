#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    multiset<int> s(B.begin(), B.end());
    for(int i : A){
        auto it = s.upper_bound(i);
        if(it == s.end()) s.erase(s.begin());
        else{
            s.erase(it);
            answer++;
        }
    }
    return answer;
}
