#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> rot(vector<vector<int>> &key){
    int N = key.size();
    vector<vector<int>> temp(N, vector<int>(N, 0));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            temp[i][j] = key[N-1-j][i];
    return temp;
}
vector<vector<int>> updown(vector<vector<int>> &key, const char ud){
    int N = key.size(), i = 0;
    vector<vector<int>> temp;
    if(ud == 'u') i++;
    if(ud == 'd') {
        N--;
        temp.push_back(vector(N,0));
    }
    for(;i < N; i++)
        temp.push_back(key[i]);
    if(ud == 'u') temp.push_back(vector(N,0));
    return temp;
}
vector<vector<int>> leftright(vector<vector<int>> &key, const char ud){
    int N = key.size(), i = 0;
    vector<vector<int>> temp(N, vector<int>(N, 0));
    if(ud == 'l') i++;
    if(ud == 'r') N--;
    for(int j = 0; j < key.size(); j++){
        for(int a = 0; a+i < N; a++){
            temp[j][a+i] = key[j][a+key.size()-N];
        }
    }
    
    return temp;
}
bool isReal(vector<vector<int>> &key, vector<vector<int>> &lock){
    for(int i = 0; i < key.size(); i++)
        for(int j = 0; j < key.size(); j++)
            if(key[i][j] + lock[i][j] != 1) return false;
    return true;
}
bool searchLR(vector<vector<int>> &key, vector<vector<int>> &lock){
    int N = key.size();
    if(isReal(key, lock)) return true;
    vector<vector<int>> lkey = key, rkey = key;
    for(int i = 0; i < N; i++){
        if(isReal(lkey, lock)) return true;
        if(isReal(rkey, lock)) return true;
        lkey = leftright(lkey, 'l');
        rkey = leftright(rkey, 'r');
    }
    return false;
}

bool searchUD(vector<vector<int>> &key, vector<vector<int>>& lock){
    int N = key.size();
    if(searchLR(key,lock)) return true;
    vector<vector<int>> ukey = key, dkey = key;
    for(int i = 0; i < N; i++){
        if(searchLR(ukey,lock)) return true;
        if(searchLR(dkey,lock)) return true;
        ukey = updown(ukey, 'u');
        dkey = updown(dkey, 'd');
    }
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int sum = 0, sum2 = 0;
    for(int i = 0; i < lock.size(); i++){
        for(int j = 0; j < lock.size(); j++){
            sum += lock[i][j];
        }
    }
    if(sum == lock.size() * lock.size()) {
        return true;
    }
    if(key.size() < lock.size()){
        for(int i = 0; i < key.size(); i++) while(lock.size() > key[i].size()) key[i].push_back(0);
        while(key.size() < lock.size())key.push_back(vector<int>(lock.size(),0));
    }
    for(int i = 0; i < 4; i++){
        if(searchUD(key,lock)) return true;
        key = rot(key);
    }
    return false;
}
