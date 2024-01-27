#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N = 10;
vector<int> fin;
int _max = 0;

void ddfs(int cur, int remain, int lscore, int pscore, int* v,vector<int> &peach) {
    if(cur == 10) {
        v[10] = remain;
        if(_max < lscore - pscore) {
            fin = vector<int>(v, v + 11);
            _max = lscore - pscore;
        }
        else if(_max == lscore - pscore && lscore != pscore) {
            for(int a = 10; a >= 0; a--) {
                if(v[a] > fin[a]) {
                    fin = vector<int>(v, v + 11);
                    break;
                }
                else if(v[a] < fin[a]) break;
            }
        }
        return;
    }
    if(peach[cur] < remain) {
        v[cur] = peach[cur] + 1;
        ddfs(cur + 1, remain - (peach[cur] + 1), lscore + (N - cur), pscore, v, peach);
    }
    v[cur] = 0;
    ddfs(cur + 1, remain, lscore, pscore + (int)((peach[cur] > 0) ? (N - cur) : 0), v, peach);
}

vector<int> solution(int n, vector<int> info) {
    int arr[11];
    ddfs(0, n, 0, 0, arr, info);
    if(fin.empty()) return {-1};
    return fin;
}
