#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = -1;
    long long l = 0, r = (long long)times[0]*(long long)n, mid, c;
    while(l < r)
    {
        mid = (l+r)/2;
        c = 0;
        for(long long i : times) c += (long long)(mid/i);
        if(n > c) l = mid+1;
        if(n <= c) r = mid;
        //if(N == c) answer = mid;
    }

    return answer = r;
}
