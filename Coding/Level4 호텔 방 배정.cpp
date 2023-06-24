#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    map<long long, long long> m;
    m[-1] = -1;
    m[k+2] = k+2;
    for(long long num : room_number){
        auto piv = m.upper_bound(num);
        auto aft = piv--;
        if(piv->second + 1 >= num){
            piv->second++;
            answer.push_back(piv->second);
            if(piv->second + 1 == aft->first){
                piv->second = aft->second;
                m.erase(aft);
            }
        }
        else{
            answer.push_back(num);
            if(num + 1 == aft->first){
                long long temp = aft->second;
                m.erase(aft);
                m[num] = temp;
            }
            else m[num] = num;
        }
        
    }
    
    return answer;
}
