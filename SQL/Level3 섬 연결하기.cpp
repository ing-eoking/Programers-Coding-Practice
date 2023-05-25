#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define SWAP(a,b) {a^=b^=a^=b;}

bool cmp(vector<int> & a, vector<int> & b)
{
    sort(a.begin(),a.end()-1);
    sort(b.begin(),b.end()-1);
    return a.back() < b.back();
}
int get_parent(int n, vector<int> &uni)
{
    if(uni[n] == n)return uni[n];
    else return get_parent(uni[n], uni);
}
bool test(vector<int> &uni)
{
    int s = 0;
    for(int i : uni) s += i;
    return (s == 0);
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<int> uni(n);
    for(int i = 0; i< n; i++) uni[i]= i;
    sort(costs.begin(), costs.end(), cmp);
    int al = 0;
    for(auto i : costs)
    {
        if(uni[i[0]] != uni[i[1]]) {
            uni[uni[i[1]]] = uni[i[0]];
            answer += i[2];
        }
        for(int i = 0; i< uni.size(); i++) uni[i] = get_parent(i,uni);
        if(test(uni)) break;
    }
    return answer;
}
