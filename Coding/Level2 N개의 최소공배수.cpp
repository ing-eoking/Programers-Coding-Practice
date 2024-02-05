#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    vector<int> v1 = arr;
    while(v1.size() > 1){
        vector<int> v2;
        for(int i = 0; i < v1.size(); i += 2)
            if(i == v1.size() - 1) v2.push_back(v1[i]);
            else v2.push_back(v1[i] / __gcd(v1[i], v1[i + 1]) * v1[i + 1]);
        v1 = v2;
    }
    return v1[0];
}
