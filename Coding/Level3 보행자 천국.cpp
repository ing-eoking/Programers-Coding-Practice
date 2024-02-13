#include <vector>
#include <iostream>

using namespace std;

int MOD = 20170805;
#define r_over(r, m) (r < 0 || r >= m)
#define c_over(c, n) (c < 0 || c >= n)

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0, i = 1, j = 1;
    vector<vector<int>> dp(m, vector<int>(n));
    
    while(!r_over(i, m) && city_map[i][0] == 2) i++;
    if(!r_over(i, m) && city_map[i][0] == 0) dp[i][0] = 1;
    while(!c_over(j, n) && city_map[0][j] == 2) j++;
    if(!c_over(j, n) && city_map[0][j] == 0) dp[0][j] = 1;
    j++;
    for(i = 0; i < m; i++) {
        for(; j < n; j++) {
            if(city_map[i][j] == 0) {
                if(!r_over(i - 1, m)) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                if(!c_over(j - 1, n)) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            }
            else if(city_map[i][j] == 2) {
                 if(!r_over(i - 1, m) && city_map[i - 1][j] == 0) {
                     int r = i + 1;
                     while(!r_over(r, m) && city_map[r][j] == 2) r++;
                     if(!r_over(r, m) && city_map[r][j] == 0) 
                         dp[r][j] = (dp[r][j] + dp[i - 1][j]) % MOD;
                 }
                 if(!c_over(j - 1, n) && city_map[i][j - 1] == 0) {
                     int c = j + 1;
                     while(!c_over(c, n) && city_map[i][c] == 2) c++;
                     if(!c_over(c, n) && city_map[i][c] == 0) 
                         dp[i][c] = (dp[i][c] + dp[i][j - 1]) % MOD;
                 }
            }
            else continue;
        }
        j = 0;
    }
    return dp[m - 1][n - 1];
}
