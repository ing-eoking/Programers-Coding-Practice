#include <string>
#include <vector>
#include <iostream>

using namespace std;


int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    vector<vector<int>> sum(board.size()+1, vector<int>(board[0].size()+1));
    for(auto i : skill){
        int degree = ((i[0] == 1) ? -1 : 1) * i[5];
        sum[i[1]][i[2]] += degree;
        sum[i[3]+1][i[4]+1] += degree;
        sum[i[1]][i[4]+1] -= degree;
        sum[i[3]+1][i[2]] -= degree;
    }
    for(int i = 1; i < sum[0].size(); i++)
        for(int j = 0; j < sum.size(); j++)
            sum[j][i] += sum[j][i-1];
    for(int i = 1; i < sum.size(); i++)
        for(int j = 0; j < sum[0].size(); j++)
            sum[i][j] += sum[i-1][j];
    for(int i = 0; i < board.size(); i++)
        for(int j = 0; j < board[i].size(); j++)
            if((board[i][j] += sum[i][j]) > 0) answer++;

    return answer;
}
