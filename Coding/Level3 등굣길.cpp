#include <string>
#include <vector>
#include <iostream>

using namespace std;

int path(int n, int m, vector<vector<int>> &v)
{
    if(m < 1 || n < 1) return 0;
    else if(v[n-1][m-1] < 0) return 0;
    else if(v[n-1][m-1] > 0) return v[n-1][m-1];
    else if(v[n-1][m-1] == 0) return v[n-1][m-1] = (path(n-1, m,v) + path(n, m-1,v))%1000000007;
}
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> v(m,vector<int>(n,0));
    v[0][0] = v[0][1] = v[1][0] = 1;
    for(auto i : puddles) v[i[0]-1][i[1]-1] = -1;
    return answer = path(m,n,v);
}
