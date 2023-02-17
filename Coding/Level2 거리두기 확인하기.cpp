#include <string>
#include <vector>
#include <iostream>

using namespace std;
bool tf(const int y, const int x, vector<string> &p){
    if(y < 4 && p[y+1][x] == 'P') return false;
    if(x < 4 && p[y][x+1] == 'P') return false;
    if(y < 3 && p[y+2][x] == 'P' && p[y+1][x] != 'X') return false;
    if(x < 3 && p[y][x+2] == 'P' && p[y][x+1] != 'X') return false;
    if(y < 4 && x > 0 && p[y+1][x-1] == 'P' && (p[y+1][x] != 'X' || p[y][x-1] != 'X')) return false;
    if(y < 4 && x < 4 && p[y+1][x+1] == 'P' && (p[y+1][x] != 'X' || p[y][x+1] != 'X')) return false;
    return true;
    
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(auto place : places){
        int temp = 1;
        for(int i = 0; i < 25; i++){
            int y = i/5, x = i%5;
            if(place[y][x] == 'P')
                if(!(temp = tf(y,x,place))) break;
        }
        answer.push_back(temp);
    }
    return answer;
}
