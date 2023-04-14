#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define MOD 1000000007

unsigned long long search(int n, int count, vector<vector<unsigned long long>> &dp){
    if(n == 0 && count == 0) return 1;
    if(n == 0 || count == 0) return 0;
    if( n < 0 || n < count) return 0;
    if(dp[n][count] == 0){
        unsigned long long temp1 = 0, temp2 = 0;
        temp1 = search(n -1, count - 1, dp) %MOD;
        temp2 = search(n - 1, count, dp) % MOD;
        temp2 = temp2 * (n - 1) * 2 % MOD;
        return dp[n][count] = (temp1 + temp2) % MOD;
    }
    else return dp[n][count] % MOD;
}

int solution(int n, int count) {
    vector<vector<unsigned long long>> dp(n+1, vector<unsigned long long>(n+1));
    dp[0][0] = 1;
    return search(n, count, dp) % MOD;
}
