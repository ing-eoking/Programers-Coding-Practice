#include <string>
#include <vector>
#include <set>

using namespace std;

int getP(int i, vector<int> &uni){
    if(i == uni[i]) return i;
    else return getP(uni[i], uni);
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int> uni(n);
    for(int i = 0; i<n; i++) uni[i] = i;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if((computers[i][j]|computers[j][i]) == 1)
            {
                uni[i] = getP(i, uni);
                uni[j] = getP(j, uni);
                if(uni[i] > uni[j]) uni[uni[i]] = uni[j];
                else uni[uni[j]] = uni[i];
            }
        }
    }
    for(int i = 0; i<n; i++)
        uni[i] = getP(i,uni);
    set<int> s(uni.begin(), uni.end());
    return answer = s.size();

}
