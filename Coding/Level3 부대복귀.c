#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n, int** roads, size_t roads_rows, size_t roads_cols, int sources[], size_t sources_len, int destination) {
    int *answer = (int *)malloc(sizeof(int)* sources_len);
    int *dist = (int *)malloc(sizeof(int) * n);
    int **link = (int **)malloc(sizeof(int *) * n);
    int *sz = (int *)malloc(sizeof(int) * n);
    destination--;
    for(int i = 0; i < n; i++) link[i] = (int *)malloc(0);
    memset(sz, 0, n * sizeof(int));
    memset(dist,-1, n * sizeof(int));
    dist[destination] = 0;
    for(int i = 0; i < roads_rows; i++){
        roads[i][0]--; roads[i][1]--;
        sz[roads[i][0]]++;
        sz[roads[i][1]]++;
        link[roads[i][0]] = realloc(link[roads[i][0]], sizeof(int) * sz[roads[i][0]]);
        link[roads[i][1]] = realloc(link[roads[i][1]], sizeof(int) * sz[roads[i][1]]);
        link[roads[i][0]][sz[roads[i][0]] - 1] = roads[i][1];
        link[roads[i][1]][sz[roads[i][1]] - 1] = roads[i][0];
    }
    bool * visit = (bool *)malloc(sizeof(bool)*n);
    int * child = (int *)malloc(sizeof(int)*(n+1));
    int d = 0, st = 0, ed = 1;
    memset(visit, false, sizeof(bool)*n);
    visit[destination] = true;
    child[st] = destination;
    while(st < ed){
        int tst = ed;
        for(int i = st; i < ed; i++)
            for(int j = 0; j < sz[child[i]]; j++)
                if(!visit[link[child[i]][j]]){
                    child[tst++] = link[child[i]][j];
                    visit[link[child[i]][j]] = true;
                    dist[link[child[i]][j]] = dist[child[i]] + 1;
                }
        st = ed;
        ed = tst;
    }
    for(int i = 0; i < sources_len; i++) answer[i] = dist[sources[i] - 1];
    return answer;
}
