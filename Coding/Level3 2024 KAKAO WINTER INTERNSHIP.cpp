#include <string>
#include <vector>
#include <iostream>

using namespace std;
#define DIV 10007

int solution(int n, vector<int> tops) {
    int answer = 0;
    bool above;
    vector<int> dp(2*n+2);
    dp[1] = 1;
    dp[2] = 2 + tops[0];
    for(int i = 3; i <= 2*n + 1; i++){
        above = (i % 2 == 0) && tops[i / 2 - 1];
        dp[i] = (dp[i - 1] * (above + 1) + dp[i - 2]) % DIV;
    }

    return dp[2*n + 1];
}
