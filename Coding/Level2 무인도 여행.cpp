#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int dfs(int x, int y, vector<string> &m){
    if(x < 0 || x >= m.size()) return 0;
    if(y < 0 || y >= m[x].size()) return 0;
    if(m[x][y] == 'X') return 0;
    int sum = m[x][y] - '0';
    m[x][y] = 'X';
    for(int i = 0; i < 4; i++){
        sum += dfs(x + dx[i], y + dy[i], m);
    }
    return sum;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    for(int i = 0; i < maps.size(); i++)
        for(int j = 0; j < maps[i].size(); j++) 
            if(maps[i][j] != 'X') 
                answer.push_back(dfs(i, j, maps));
    if(answer.empty()) return {-1};
    sort(answer.begin(), answer.end());
    return answer;
}
