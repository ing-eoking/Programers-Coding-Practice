#include <string>
#include <vector>

using namespace std;

#define isS(a) (a <= 'z' && a >= 'a')
#define isB(a) (a <= 'Z' && a >= 'A')

string solution(string s) {
    string answer = "";
    if(isS(s[0])) s[0] += ('A' - 'a');
    for(int i = 1; i < s.length(); i++)
        if(s[i - 1] == ' ' && isS(s[i])) s[i] += ('A'- 'a');
        else if(s[i-1] != ' ' && isB(s[i])) s[i] += ('a' - 'A');
    return s;
}
