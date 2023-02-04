#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

int comb(int n, int r)
{
    if(n == r || r == 0 || n < r) 
        return 1; 
    else 
        return comb(n - 1, r - 1) + comb(n - 1, r);
}

bool cmp(string a, string b){
    if(a.length() != b.length()) return false;
    for(int i = 0; i < a.length(); i++){
        if(b[i] == '*') continue;
        if(a[i] != b[i]) return false;
    }
    return true;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    set<string> s;
    for(auto i : user_id)
        for(auto j : banned_id)
            if(cmp(i,j)) s.insert(i);
    vector<string> v(s.begin(), s.end());
    set<set<string>> ss;
    do {
        int cor = 0;
        for(int i = 0; i<banned_id.size(); i++){
            if(cmp(v[i], banned_id[i]))cor++;
        }
        if(cor == banned_id.size()){
            ss.insert(set<string>(&v[0], &v[banned_id.size()]));
        }
    } while (next_permutation(v.begin(), v.end()));
    return answer = ss.size();
}
