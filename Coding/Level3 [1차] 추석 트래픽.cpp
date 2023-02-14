#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

#define SWAP(a,b) a^=b^=a^=b

int solution(vector<string> lines) {
    int answer = 0;
    vector<vector<int>> time;
    vector<int> arr(0,3000);
    for(auto i : lines)
    {
        int temp = stoi(i.substr(11,2))*1000*60*60 + stoi(i.substr(14,2))*1000*60
            + stoi(i.substr(17,2))*1000 + stoi(i.substr(20,3));
        int sp = (int)(stod(i.substr(24,i.length()-1))*1000);
        time.push_back({temp-sp+1, temp});      
    }
    sort(time.begin(), time.end());
    for(auto i : time){
        for(auto j : i)
        {
            for(int k = 0; k < 2; k++){
                int low = j;
                int hig = (k*2 - 1)*999 + j;
                int tt = 0;
                low>hig?SWAP(low,hig):true;
                for(int m = 0; m < time.size(); m++){
                    if(time[m][0] > hig || time[m][1] < low) continue;
                    tt++;
                }
                if(tt > answer) answer = tt;
            }
        }
    }

    return answer;
}
