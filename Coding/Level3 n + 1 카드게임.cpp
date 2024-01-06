#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int coin, vector<int> cards) {
    int answer = 1, cur;
    int N = cards.size();
    int able = 0;
    int noeffi = 0;
    vector<int> need(N+1);
    for(int i = 0; i < N; i++)
        need[N+1 - cards[i]] = i;
    for(int i = 0; i < N / 3; i++)
        if(need[cards[i]] < N / 3) able++;
    able /= 2;
    
    for(int i = N / 3; i < N; i+=2) {
        if(coin) 
            if(need[cards[i + 1]] == i) noeffi++;
            else 
                for(int j = 0; j < 2; j++)
                    if(need[cards[i + j]] < i + 2)
                        if(need[cards[i + j]] >= N / 3) noeffi++;
                        else if (coin) {
                            int add = (need[cards[i + j]] < i + 2);
                            coin -= add;
                            able += add;
                        }

        if (coin > 1 && noeffi && !able) {
            noeffi--;
            coin -= 2;
            able++;
        }
        if (!able) break;
        able--;
        answer++;
    }
    
    return answer;
}
