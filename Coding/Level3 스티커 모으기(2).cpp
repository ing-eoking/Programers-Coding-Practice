#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int big(vector<int>::iterator b, vector<int>::iterator e)
{
    vector<int> v(b,e);
    if(v.size() < 1) return 0;
    if(v.size() == 1) return v[0];
    if(v.size() == 2) return max(v[0], v[1]);
    int sum = 0;
    v[2] += v[0];
    for(int i = 3; i < v.size(); i++)
        v[i] = max(v[i]+v[i-2], v[i]+v[i-3]);
    return sum = max(v[v.size()-1], v[v.size()-2]);
}

int solution(vector<int> sticker)
{
    if(sticker.size() == 1) return sticker[0];
    if(sticker.size() == 2) return max(sticker[0], sticker[1]);
    else return max(sticker[0]+big(++++sticker.begin(), --sticker.end()), big(++sticker.begin(), sticker.end()));
}
