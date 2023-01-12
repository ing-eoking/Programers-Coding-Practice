#include <string>
using namespace std;

int solution(string s)
{
    bool TF = false;
    for(int i = s.length(); i >= 2; i--){
        for(int j = 0; j <= s.length() - i; j++){
            string temp(s.begin()+j, s.begin()+i+j);
            TF = true;
            for(int k = 0; k < temp.length()/2; k++)
                if(temp[k] != temp[temp.length()-1-k]) {
                    TF = false;
                    break;
                }
            if(TF) return i;
        }
    }
    return 1;
}
