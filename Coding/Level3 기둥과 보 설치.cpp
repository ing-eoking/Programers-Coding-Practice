#include <string>
#include <vector>
#include <set>

using namespace std;
vector<vector<vector<bool>>> board;
int N = 0;
bool isC(int x, int y, bool a){
    if(a && ((y > 0 && (board[x][y-1][0] || board[x+1][y-1][0]))
            || (x > 0 && x < N && board[x - 1][y][1] && board[x + 1][y][1]))) return true;
    if(!a && ((y == 0) || (x > 0 && board[x-1][y][1])
              || (x < N && board[x][y][1])
              || (y > 0 && board[x][y - 1][0]))) return true;
    return false;
}
bool isXD(int x, int y, bool a){
    if(!a && ((x > 0 && board[x - 1][y + 1][1] && !isC(x-1, y +1, 1))
        || (board[x][y+1][1] && !isC(x, y+1, 1))
        || (y < N && board[x][y+1][0] && !isC(x, y+1, 0)))) return true;
    if(a && ((board[x][y][0] && !isC(x,y,0)) 
              || (board[x+1][y][0] && !isC(x+1, y, 0))
             || (x > 0 && board[x-1][y][1] && !isC(x-1,y,1))
             || (x < N && board[x+1][y][1] && !isC(x+1,y,1)))) return true;
    return false;
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    set<vector<int>> s;
    N = n;
    board = vector<vector<vector<bool>>>(n+1, vector<vector<bool>>(n+1, vector<bool>(2)));
    for(auto i : build_frame){
        if(i[3]){
            if(isC(i[0], i[1], i[2])){
                board[i[0]][i[1]][i[2]] = true;
                s.insert({i[0], i[1], i[2]});
            }
        }
        else{
            board[i[0]][i[1]][i[2]] = false;
            if(isXD(i[0], i[1], i[2])) board[i[0]][i[1]][i[2]] = true;
            else s.erase({i[0], i[1], i[2]});
        }
    }
    vector<vector<int>> answer(s.begin(), s.end());
    return answer;
}
