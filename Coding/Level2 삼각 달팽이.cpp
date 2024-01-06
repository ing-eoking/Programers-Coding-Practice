#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> v;
    int c = 0;
    int num = 1;
    for(int i = 1; i <= n; i++) v.push_back(vector<int>(i));
    int y = 0, x= 0;
    while(num <= n * (n + 1) / 2){
        while(y < n && v[y][x] == 0){
            v[y][x] = num++;
            y++;
        }
        y--;
        x++;
        while(x < v[y].size() && v[y][x] == 0){
            v[y][x] = num++;
            x++;
        }
        x-=2;
        y--;
        while(x >= 0 && y >= 0 && v[y][x] == 0){
            v[y][x] = num++;
            x--;
            y--;
        }
        x++;
        y+=2;
    }

    for(auto i : v){
        for(auto j : i) answer.push_back(j);
    }
    return answer;
}
