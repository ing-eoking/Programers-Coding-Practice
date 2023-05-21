#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

string cor(string a, string b){
    string q = "";
    set<char> s(a.begin(), a.end());
    for(auto i : b) if(s.find(i) != s.end()) q += i;
    sort(q.begin(), q.end());
    return q;
}
bool cmp(pair<string, int> a, pair<string, int> b){
    if(a.first.length() == b.first.length()) return a.second > b.second;
    return a.first.length() < b.first.length();
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    map<string, int> m;
    for(int i = 0; i< orders.size(); i++){
        for(int j = i+1; j< orders.size(); j++){
            string temp = cor(orders[i],orders[j]);
            if(temp.length() > 1){
                for(auto a : course){
                    if(a > temp.length()) break;
                    vector<bool> tf(temp.length() - a, false);
                    tf.insert(tf.end(), a, true);
                    do{
                        string te = "";
                        for(int k = 0; k < temp.length(); k++)
                            if(tf[k])te += temp[k];
                        m[te] = 0;
                    }while(next_permutation(tf.begin(), tf.end()));
                }
            }
        }
    }
    for(auto i : m){
        for(auto j : orders){
            if(cor(i.first, j) == i.first) m[i.first]++;
        }
    }
    vector<pair<string, int>> v(m.begin(),m.end());
    sort(v.begin(), v.end(), cmp);
    int ss = v[0].first.length(), n = v[0].second;
    for(int i = 0; i< v.size(); i++)
    {
        if(v[i].first.length() != ss){
            ss = v[i].first.length();
            n = v[i].second;
            continue;
        }
        if(v[i].second < n) m.erase(v[i].first);
    }
    for(auto i : m) answer.push_back(i.first);
    return answer;
}
