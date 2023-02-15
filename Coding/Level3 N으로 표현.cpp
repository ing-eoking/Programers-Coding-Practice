#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

#define SWAP(a,b) {a^=b^=a^=b;}


int solution(int N, int number) {
    int answer = 0;
    if(N == number) return 1;
    set<long long> s;
    vector<vector<long long>> v(8);
    for(int i = 0; i < v.size(); i++)
    {
        v[i].push_back(pow(10,i)*N);
        if(i>0) v[i][0] += v[i-1][0];
        if(v[i][0] == number) return i+1;
        s.insert(v[i][0]);
    }
    vector<long long> sum(4,0);
    for(int i = 1; i<v.size(); i++)
    {
        for(int j = 0; j <= (i-1)/2; j++)
        {
            int k = i-1-j;
            for(int m = 0; m<v[j].size(); m++)
            {
                for(int n = 0; n<v[k].size(); n++)
                {
                    sum[0] = v[j][m]+v[k][n];
                    sum[1] = abs(v[j][m]-v[k][n]);
                    if(v[j][m] > v[k][n] && v[k][n] != 0)sum[2] = v[j][m]/v[k][n];
                    else if(v[j][m] != 0) sum[2] = v[k][n]/v[j][m];
                    sum[3] = v[j][m]*v[k][n];

                    for(int l = 0; l<4; l++)
                    {
                        if(sum[l] == number) return answer = i + 1;
                        if(s.insert(sum[l]).second) v[i].push_back(sum[l]);
                    }
                }
            }
        }
    }

    return answer = -1;
}
