#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> s;
    for(auto i : operations)
    {
        int num = stoi(i.substr(2));
        switch(i[0])
        {
            case 'I':
                s.insert(num);
                break;
            case 'D':
                if(!s.empty())
                    if(num == 1) s.erase(--s.end());
                    else if(num == -1) s.erase(s.begin());
                break;
            default :
                break;
                
        }
    }
    answer.push_back(s.empty()?0:(*(--s.end())));
    answer.push_back(s.empty()?0:(*s.begin()));
    return answer;
}
