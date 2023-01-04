#include <vector>
#include <string>
#include <iostream>

using namespace std;

#define MAX_NUM 2147483647
#define MIN_NUM -2147483648
#define MAX(a,b) a > b ? a : b
#define MIN(a,b) a > b ? b : a

int solution(vector<string> arr)
{
    int N = (arr.size() + 1) / 2;
    vector<vector<int>> amax(N,vector<int>(N, MIN_NUM));
    vector<vector<int>> amin(N,vector<int>(N, MAX_NUM));
    for(int i = 0; i < N; i++) amax[i][i] = amin[i][i] = stoi(arr[2*i]);
    for(int l = 1; l < N; l++){
        for(int i = 0; i+l< N; i++){
            for(int k = i; k+1 <= i+l; k++){
                if(arr[2*k+1] == "+"){
                    amax[i][l+i] = MAX(amax[i][l+i], amax[i][k]+amax[k+1][i+l]);
                    amin[i][l+i] = MIN(amin[i][l+i], amin[i][k]+amin[k+1][i+l]);
                }
                else{
                    amax[i][l+i] = MAX(amax[i][l+i], amax[i][k]-amin[k+1][i+l]);
                    amin[i][l+i] = MIN(amin[i][l+i], amin[i][k]-amax[k+1][i+l]);
                }
            }
        }
    }
    return amax[0][N-1];
}
