#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<string> V = {"A", "E", "I", "O", "U"};
set<string> s;
int solution(string word) {
    int answer = 0;
    for(string a : V){
        s.insert(a);
        for(string b : V){
            s.insert(a+b);
            for(string c : V){
                s.insert(a+b+c);
                for(string d : V){
                    s.insert(a+b+c+d);
                    for(string e : V) s.insert(a+b+c+d+e);
                }
            }
        }
    }
    return answer = distance(s.begin(), s.find(word))+1;
}
