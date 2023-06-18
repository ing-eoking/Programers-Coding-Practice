#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// info_len은 배열 info의 길이입니다.
// edges_rows는 2차원 배열 edges의 행 길이, edges_cols는 2차원 배열 edges의 열 길이입니다.
int edge[17][3];
int _max = 0;
void makeTree(int parent, int cur){
    for(int i = 0; i < 3; i++)
        if(edge[cur][i] == parent) edge[cur][i] = -1;
        else if(edge[cur][i] >= 0) makeTree(cur, edge[cur][i]);
}
void search(int node, int sheep, int wolf, bool able[], int info[]){
    if(info[node] == 0) sheep++;
    else wolf++;
    if(wolf >= sheep) return;
    if(_max < sheep) _max = sheep;
    bool ab[17];
    memcpy(ab, able, 17 * sizeof(bool));
    ab[node] = false;
    for(int i = 0; i < 3; i++)
        if(edge[node][i] >= 0) ab[edge[node][i]] = true;
    for(int i = 0; i < 17; i++)
        if(ab[i]) search(i, sheep, wolf, ab, info);
}

int solution(int info[], size_t info_len, int** edges, size_t edges_rows, size_t edges_cols) {
    int answer = 0, idx;
    memset(edge, -1, sizeof(edge));
    for(int i = 0; i < edges_rows; i++){
        idx = 0;
        while(edge[edges[i][0]][idx] >= 0) idx++;
        edge[edges[i][0]][idx] = edges[i][1];
        idx = 0;
        while(edge[edges[i][1]][idx] >= 0) idx++;
        edge[edges[i][1]][idx] = edges[i][0];
    }
    makeTree(-2, 0);
    int able[17] = {0,};
    search(0,0,0, able, info);
    return _max;
}
