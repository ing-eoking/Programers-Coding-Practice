#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    string splt;
    istringstream is(s);
    while(getline(is, splt, ' ')){
        for(int i = 0; i < splt.length(); i++)
            if(i % 2) answer += tolower(splt[i]);
            else answer += toupper(splt[i]);
        answer += ' ';
    }
    if(s.back() != ' ') answer.pop_back();
    return answer;
}
