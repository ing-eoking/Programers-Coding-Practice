#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

bool isPrime(long long n){
    if(n < 2) return false;
    for(long long i = 2; i*i <= n; i++)
        if(n % i == 0) return false;
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string tran = "";
    while(n > 0){
        tran += to_string(n%k);
        n = n/k;
    }
    reverse(tran.begin(), tran.end());
    istringstream ss(tran);
    string stringBuffer;
    while (getline(ss, stringBuffer, '0')){
        //x.push_back(stringBuffer);
        if(!stringBuffer.empty() && isPrime(stoll(stringBuffer))) answer++;
    }
    
    return answer;
}
