#include <string>
#include <vector>

using namespace std;

#define MIN(a,b) (a) > (b) ? (b) : (a)

const int arr[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int dfs(vector<vector<bool>>& map, int x, int y, const int &dx, const int &dy){
    if(x == dx && y == dy) return 1;
    map[y][x] = false;
    for(int i = 0; i < 4; i++)
        if(map[y+arr[i][1]][x+arr[i][0]])
            return dfs(map, x + arr[i][0], y + arr[i][1], dx, dy) + 1;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    vector<vector<bool>> map(103,vector<bool>(103,false));
    for(vector<int> & v : rectangle)
        for(int x = v[0]*2; x <= v[2]*2; x++)
            for(int y = v[1]*2; y <= v[3]*2; y++) map[y][x] = true;
    for(vector<int> & v : rectangle)
        for(int x = v[0]*2+1; x <= v[2]*2-1; x++)
            for(int y = v[1]*2+1; y <= v[3]*2-1; y++) map[y][x] =false;
    characterX = characterX*2;
    characterY = characterY*2;
    map[characterY][characterX] = false;
    vector<vector<int>> temp;
    for(int i = 0; i < 4; i++)
        if(map[characterY - arr[i][0]][characterX - arr[i][1]])
            temp.push_back({characterX - arr[i][1],characterY - arr[i][0]});
    int a = dfs(map, temp[0][0], temp[0][1],itemX*2, itemY*2);
    int b = dfs(map, temp[1][0], temp[1][1],itemX*2, itemY*2);
    return MIN(a/2, b/2);
}
