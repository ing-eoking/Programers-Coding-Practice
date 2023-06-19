#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// s_len은 배열 s의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* s[], size_t s_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char** answer = (char**)malloc(s_len*sizeof(char*));
    char str[1000001];
    int idx = 0, zero = 0, one = 0, pat = 0, sidx = 0;
    for(int i = 0; i < s_len; i++){
        idx = one = pat = sidx = 0;
        while(s[i][idx] != '\0'){
            if(s[i][idx] == '1') one++;
            else{
                if(one < 2){
                    while(one) {str[sidx++] = '1'; one--;}
                    str[sidx++] = '0';
                }
                else{
                    pat++;
                    one -=2;
                }
            }
            idx++;
        }

        while(pat--){
            str[sidx] = str[sidx + 1] = '1';
            str[sidx+2] = '0';
            sidx += 3;
        }
        while(one--) str[sidx++] = '1';
        str[sidx] = '\0';
        answer[i] = (char *)malloc(sizeof(char) * (idx+1));
        strcpy(answer[i], str);

    }
    return answer;
}
