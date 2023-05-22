#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    vector<int> c(e+1, 0), m(e+1, e);
    for(int i = 2; i <= e; i++)
        for(int j = 1; j < min(e/i + 1,i); j++)
            c[i*j] += 2;
    for(int i = 1; i < (int)sqrt(e) + 1; i++)
            c[i*i]++;
    for(int i = e - 1; i >= 0; i--) 
        m[i] = c[i] >= c[m[i+1]] ? i : m[i + 1];
    for(int i : starts)
        answer.push_back(m[i]);
    return answer;
}
