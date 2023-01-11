#include <string>
#include <vector>
using namespace std;

static int PM[4][2] = {{0,1},{0,-1},{1,0},{-1,0}}; 

typedef vector<vector<int>> VVI;
typedef vector<int> VI;

#define MIN(a,b) a > b ? b : a
#define MAX(a,b) a > b ? a : b

int MP[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
int OVER[2]= {-1,50};
void dfs2 (bool tf, int y, int x, VI &square, VVI & board){
    board[y][x] = !tf;
    for(int i = 0; i < 4; i++){
        int Y = y+MP[i][0], X = x+MP[i][1];
        if(X != OVER[i/2] && Y != OVER[i/2] && board[Y][X] == tf){
                square[0] = MIN(square[0], Y);
                square[1] = MIN(square[1], X);
                square[2] = MAX(square[2], Y);
                square[3] = MAX(square[3], X);
                dfs2(tf, Y, X,square,board);
        }
    }
}
void rot(vector<vector<bool>> & board){
    vector<vector<bool>> temp(board[0].size(),vector<bool>(board.size()));
    for(int i = 0; i <temp.size(); i++)
        for(int j = 0; j <temp[0].size(); j++)
            temp[i][j] = board[board.size()-j-1][i];
    board = temp;
}
int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = -1;
    OVER[1] = game_board.size();
    vector<vector<vector<bool>>> B, T;
    vector<int> score;
    for(int i = 0; i < OVER[1]; i++)
        for(int j = 0; j < OVER[1]; j++){
            if(game_board[i][j] == 0){
                vector<vector<int>> temp = game_board;
                B.push_back(vector<vector<bool>>());
                VI sq({i,j,i,j});
                dfs2(0,i,j,sq, game_board);
                for(int y = sq[0]; y <= sq[2]; y++){
                    B[B.size()-1].push_back(vector<bool>());
                    for(int x = sq[1]; x <= sq[3]; x++)
                        B[B.size()-1][y - sq[0]].push_back(temp[y][x]);
                }
            }
            if(table[i][j] == 1){
                vector<vector<int>> temp = table;
                T.push_back(vector<vector<bool>>());
                score.push_back(0);
                VI sq({i,j,i,j});
                dfs2(1,i,j,sq, table);
                for(int y = sq[0]; y <= sq[2]; y++){
                    T[T.size()-1].push_back(vector<bool>());
                    for(int x = sq[1]; x <= sq[3]; x++){
                        T[T.size()-1][y - sq[0]].push_back(temp[y][x]);
                        score[score.size()-1] += temp[y][x];
                    }
                }
            }
        }
    int sum = 0;
    bool tf = false;
    vector<bool> tfB(B.size(), false);
    for(int i = 0; i < T.size(); i++){
        for(int j = 0; j < B.size(); j++){
            if(tfB[j]) continue;
            for(int a = 0; a < 4; a++){
                rot(T[i]);
                if(T[i].size() == B[j].size() && T[i][0].size() == B[j][0].size()){
                    tf = true;
                    for(int y = 0; y < T[i].size(); y++){
                        for(int x = 0; x < T[i][0].size(); x++)
                            if(T[i][y][x] + B[j][y][x] != 1){
                                tf = false;
                                break;
                            }
                        if(!tf) break;
                    }
                    if(tf){
                        sum += score[i];
                        tfB[j]= true;
                        j = B.size();
                        break;
                    }
                }
            }
        }
    }
    return sum;
}
