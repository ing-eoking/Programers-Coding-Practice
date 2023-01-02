#include <string>
#include <vector>

using namespace std;

#define ABS(a) (a>0)?(a):-(a)
#define MIN(a,b) (a>b)?(b):(a)

int solution(int n, vector<vector<int>> wires) {
    int answer = 999999;
    vector<int> ori(n);
    for(int j = 0; j < n; j++) ori[j] = j;
    for(int i = 0; i < n-1; i++){
        vector<int> con(ori.begin(), ori.end());
        int c = 0;
        for(int j = 0; j < n-1; j++){
            if(i == j) continue;
            else {
                int cur1 = wires[j][0]-1, cur2 = wires[j][1]-1;
                while(cur1 != con[cur1]) cur1 = con[cur1];
                while(cur2 != con[cur2]) cur2 = con[cur2];
                con[cur1] = con[cur2] = MIN(cur1, cur2);
            }
        }
        for(int j = 0; j < con.size(); j++){
            int cur = j;
            while(cur != con[cur]) cur = con[cur];
            if((con[j] = cur)) c++;
        }
        if(answer > (ABS(n - 2*c))) answer = ABS(n - 2*c);
    }
    return answer;
}
