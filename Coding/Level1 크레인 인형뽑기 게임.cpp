#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> st;
    int N = board.size();
    for(auto i : moves){
        int j, temp;
        for(j = 0;j < N; j++)
            if(board[j][i-1] != 0) {
                temp = board[j][i-1];
                board[j][i-1] = 0;
                break;
            }
        if(j >= N) continue;
        if(!st.empty() && st.back() == temp){
            answer += 2;
            st.pop_back();
            continue;
        }
        st.push_back(temp);
    }

    return answer;
}
