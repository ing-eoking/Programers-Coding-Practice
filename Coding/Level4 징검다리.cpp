#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(), rocks.end());
    rocks.push_back(distance);
    int l = 1, r = distance , m, st, c;
    while(l <= r)
    {
        m = (l+r)/2;
        c = st = 0;
        for(int i : rocks)
            if(i - st < m) c++;
            else st = i;
        if(c > n) r= m - 1;
        else {
            answer = answer < m ? m : answer;
            l = m + 1;
        }
    }
    return answer;
}
