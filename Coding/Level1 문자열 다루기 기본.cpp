#include <string>
#include <vector>

using namespace std;

bool cmp(string &s){
    if(s.length() != 4 && s.length() != 6) return false;
    for(char i : s) if(i < '0' || i > '9') return false;
    return true;
}

bool solution(string s) {
    return cmp(s);
}
