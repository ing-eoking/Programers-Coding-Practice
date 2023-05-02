#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define MIN(a, b) (a<b)?(a):(b)

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> v(rows, vector<int>(columns));
    for(int i=0; i < rows * columns; i++) v[i/columns][i%columns]=i+1;
    for(auto i : queries){
        i[0]--; i[1]--; i[2]--; i[3]--;
        int a1 = v[i[0]+1][i[1]], a2 = v[i[0]][i[3]-1], a3 = v[i[2]][i[1]+1], a4 = v[i[2]-1][i[3]];
        int min = MIN((MIN(a1, a2)), (MIN(a3, a4)));
        for(int j = 1; j < i[2] - i[0]; j++){
            v[i[0] + j][i[1]] = v[i[0] + j + 1][i[1]];
            v[i[2] - j][i[3]] = v[i[2] - j - 1][i[3]];
            min = MIN((min), (MIN(v[i[0] + j][i[1]],v[i[2] - j][i[3]])));
        }
        for(int j = 1; j < i[3] - i[1]; j++){
            v[i[0]][i[3]-j]=v[i[0]][i[3]-j-1];
            v[i[2]][i[1]+j]=v[i[2]][i[1]+j+1];
            min =MIN((min), (MIN(v[i[0]][i[3]-j],v[i[2]][i[1]+j])));
        }
        answer.push_back(min);
        v[i[0]][i[1]] = a1; v[i[0]][i[3]] = a2;
        v[i[2]][i[1]] = a3; v[i[2]][i[3]] = a4;
        
    }
    return answer;
}
