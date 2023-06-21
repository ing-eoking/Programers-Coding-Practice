#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define DIV 1000000007

int solution(int n, vector<int> money) {
    sort(money.begin(), money.end());
    int dp[100001][100] ={0,};
    int s[100001] {0,};
    for(int i = 0; i < money.size(); i++) {
        dp[money[i]][i] = 1;
        s[money[i]] += 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < money.size(); j++)
            if(i - money[j] >= 1){
                dp[i][j] += s[i - money[j]] % DIV;
                s[i - money[j]] -= dp[i - money[j]][j]%DIV;
                s[i] += dp[i][j]%DIV;
            }
    }
    return s[n]%DIV;
}
