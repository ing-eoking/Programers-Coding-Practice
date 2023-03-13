#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    for(int i = 1; i< triangle.size(); i++)
    {
        vector<int> temp = triangle[i];
        for(int j = 0; j < triangle[i-1].size(); j++)
        {
            if(triangle[i][j] < triangle[i-1][j]+temp[j])
                triangle[i][j] = triangle[i-1][j]+temp[j];
            if(triangle[i][j + 1] < triangle[i-1][j]+temp[j + 1])
                triangle[i][j + 1] = triangle[i-1][j]+temp[j + 1];
        }
    }
    for(int i : triangle.back())
        if(answer < i) answer = i;
    return answer;
}
