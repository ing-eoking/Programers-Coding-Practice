#include <string>
#include <vector>
#include <map>

using namespace std;

#define MAX(a,b) ((a < b) ?  (b) : (a))

int big(vector<int>::iterator b, vector<int>::iterator e)
{
    vector<int> v(b,e);
    if(v.size() < 1) return 0;
    if(v.size() == 1) return v[0];
    if(v.size() == 2) return MAX(v[0], v[1]);
    int sum = 0;
    v[2] += v[0];
    for(int i = 3; i < v.size(); i++)
        v[i] = MAX(v[i]+v[i-2], v[i]+v[i-3]);
    return sum = MAX(v[v.size()-1], v[v.size()-2]);
}

int solution(vector<int> money) {
    int answer = 0;
    return answer = MAX(money[0]+big(++++money.begin(), --money.end()), big(++money.begin(), money.end()));
}
