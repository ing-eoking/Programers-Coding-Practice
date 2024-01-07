#include <string>
#include <vector>
#include <iostream>

using namespace std;

int mini = 9999;
inline int match(const string &a, const string &b)
{
    int t = 0;
    for(int i = 0; i<a.length(); i++)
        if(a[i] == b[i]) t++;
    return t;
}
int dfs(int index, int n,const vector<vector<bool>> &d, vector<bool> v, 
    vector<string> &words, const string &target)
{
    v[index] = true;
    for(int i = 0; i< v.size(); i++)
    {
        if(!v[i] & d[index][i])
        {
            int temp = dfs(i, n+1, d, v, words, target);
        }
    }
    if(mini > n && words[index] == target) mini = n;
    return n;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    words.push_back(begin);
    int size = words.size();
    vector<vector<bool>> dist(size, vector<bool>(size, false));
    vector<bool> visit(size, false);
    for(int i = 0; i< size; i++)
        for(int j = i; j< size; j++)
            if(match(words[i],words[j]) >= words[i].length()-1) dist[i][j] = dist[j][i] = true;
    dfs(size-1,0,dist,visit,words, target);
    return answer = mini>999 ? 0 : mini;
}
