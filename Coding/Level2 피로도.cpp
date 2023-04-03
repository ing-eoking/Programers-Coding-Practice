#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    sort(dungeons.begin(), dungeons.end());
    do{
        int temp = k , i = 0;
        for(; i < dungeons.size(); i++)
            if(temp < dungeons[i][0]) break;
            else temp -= dungeons[i][1];
        if(answer < i) answer = i;
	}while(next_permutation(dungeons.begin(),dungeons.end()));
    return answer;
}
