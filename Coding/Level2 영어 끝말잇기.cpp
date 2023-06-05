#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    unordered_set<string> s;
    int i = 0;
    char ed = words[0][0];
    for(;i < words.size(); i++){
        if(ed != words[i][0] || !(s.insert(words[i])).second) return {i%n+1, i/n+1}; 
        ed = words[i].back();
    }
    return {0,0};
}
