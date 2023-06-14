#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> a) {
    int answer = 1, _min = *min_element(a.begin(), a.end());
    int l = 0, r = a.size() -1;
    int minL = a[0], minR = a.back();
    while(l < r){
        if(a[l] != _min){
            if(a[l] <= minL){
                answer++;
                minL = a[l];
            }
            l++;
        }
        if(a[r] != _min){
            if(a[r] <= minR){
                answer++;
                minR = a[r];
            }
            r--;
        }
    }
    return answer;
}
