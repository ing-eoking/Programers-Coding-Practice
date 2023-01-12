#include <string>
#include <vector>
#include <set>

using namespace std;

int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};

int solution(vector<int> arrows) {
    int answer = 0;
    set <pair<int, int>> c;
    pair<int, int> xy = make_pair(0,0);
    c.insert(xy);
    for(int i : arrows)
    {
        vector<bool> mt (4, false);
        for(int j =0; j< 4; j++)
        {
            xy.first += dx[i];
            xy.second += dy[i];
            auto it = c.insert(xy);
            mt[j] = !it.second;
        }
        if(!mt[0]) answer += mt[1]+mt[3];
    }
    return answer;
}
