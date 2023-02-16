#include <string>
#include <vector>

using namespace std;

#define ABS(x) ( ((x)<0)?-(x):(x) )

int solution(string name) {
    int answer = 0;
    string target (name.length(), 'A');
    int cur = 0;
    while(name != target)
    {
        if(target[cur] != name[cur])
        {
            if(name[cur]-target[cur] < 'Z'-name[cur]+1) answer += name[cur] - target[cur];
            else answer += 'Z' - name[cur] + 1;
            target[cur] = name[cur];
        }
        int min = 99, t_cur = 0;
        for(int i = 0; i< name.length(); i++)
            if(target[i] != name[i])
            {
                int temp;
                    if(abs(cur-i) < cur + name.length()-i) temp = ABS(cur-i);
                    else temp = cur+ name.length()-i;
                if(min > temp){
                    t_cur = i;
                    min = temp;
                }
            }
        cur = t_cur;
        if(min == 99) min = 0;
        answer += min;
    }
    
    return answer;
}
