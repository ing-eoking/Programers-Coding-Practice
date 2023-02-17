#include <string>
#include <vector>
#include <iostream>

using namespace std;
int min(vector<int> arr){
    int min = 999999;
    for(auto i : arr) if(i < min) min = i;
    return min;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    int N = board.size();
    vector<vector<vector<int>>> v(N,vector<vector<int>>(N,vector<int>(4,N*N*500+1)));
    v[0][0][1] = v[0][0][0] = v[0][0][2] = v[0][0][3] = 0;
    for(int i = 0; i < N*N; i++)
        for(int y = 0; y < N; y++){
            for(int x = 0; x < N; x++){
                if(y-1 >= 0 && board[y-1][x] == 0)
                    v[y-1][x][1] = min({v[y-1][x][1], v[y][x][0]+6, v[y][x][1]+1, v[y][x][2]+6, v[y][x][3]+6});
                if(y+1 < N && board[y+1][x] == 0)
                    v[y+1][x][0] = min({v[y+1][x][0], v[y][x][1]+6, v[y][x][0]+1, v[y][x][2]+6, v[y][x][3]+6});
                if(x-1 >= 0 && board[y][x-1] == 0)
                    v[y][x-1][3] = min({v[y][x-1][3], v[y][x][0]+6, v[y][x][1]+6, v[y][x][2]+6, v[y][x][3]+1});
                if(x+1 < N && board[y][x+1] == 0)
                    v[y][x+1][2] = min({v[y][x+1][2], v[y][x][0]+6, v[y][x][1]+6, v[y][x][2]+1, v[y][x][3]+6});
            }
        }
    return answer = min(v[N-1][N-1])*100;
}
