#include <string>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int solution(string s) {
    int answer = 9999;
    set<string> ss;
    for(int i = 1; i<=s.length()/2+1; i++){
        ss.clear();
        int a = 0;
        string ttemp = "";
        for(int j = 0; j < s.length(); j += i)
        {
            string tt;
            if(j+i > s.length()) tt = s.substr(j);
            else tt = s.substr(j,i);
            ss.insert(tt);
            if(ss.size() > 1){
                ss.erase(tt);
                if (a <= 1) ttemp += *ss.begin();
                else ttemp += to_string(a) + *ss.begin();
                ss.clear();
                ss.insert(tt);
                a= 0;
            }
            a++;
        }
        if(!ss.empty())
            if (a <= 1) ttemp += *ss.begin();
            else ttemp += to_string(a) + *ss.begin();
        if(answer > ttemp.length()) {
            answer = ttemp.length();
        }
    }
    return answer;
}
