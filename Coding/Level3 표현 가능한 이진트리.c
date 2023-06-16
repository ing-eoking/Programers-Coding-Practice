#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int* solution(long long numbers[], size_t numbers_len) {
    int* answer = (int*)malloc(numbers_len * sizeof(int));
    memset(answer, 1, sizeof(int) * numbers_len);
    for(int i = 0; i < numbers_len; i++){
        if(numbers[i] == 1) {answer[i] = 1; continue;}
        long long cmp = 1, h = 0;
        while(cmp <= numbers[i]) {cmp *=2; h++;}
        int h2 = 1;
        while(h2 - 1 < h) h2 *= 2; h2--;
        bool *bin = (bool *)malloc(sizeof(bool)*h2);
        for(int j = 0; j < h2; j++){
            bin[j] = numbers[i] % 2;
            numbers[i] /= 2;
        }
        bool tf = true;
        for(int m = 1; m < (h2 + 1) / 2; m *=2){
            for(int p = 1; p*m <= h2; p += 4){
                if((bin[p*m - 1] || bin[p*m + 2*m - 1]) && !bin[p*m+m -1]) 
                {
                    tf = false;
                    break;
                }
            }
            if(!tf) break;
        }
        answer[i] = tf;
        
    }
    return answer;
}
