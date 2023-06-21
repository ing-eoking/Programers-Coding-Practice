#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define DIV 1000000007

int solution(int n, vector<int> money) {
    vector<int> dp(n+1);
    dp[0] = 1;
    for(int m : money)
        for(int i = m; i <= n; i++)
            dp[i] += dp[i - m];
    return dp[n] % DIV;
}
