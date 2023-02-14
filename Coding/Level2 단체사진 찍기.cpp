#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    string s = "ACFJMNRT";
    do{
        bool tf = false;
        for(auto i : data){
            int comp = abs((int)(s.find(i[0]) - s.find(i[2]))) - 1, num = i[4] - '0';
            tf = false;
            if(i[3] == '=' && comp != num) break;
            if(i[3] == '>' && comp <= num) break;
            if(i[3] == '<' && comp >= num) break;
            tf = true;
        }
        if(tf) answer++;
	}while(next_permutation(s.begin(),s.end()));
    return answer;
}
