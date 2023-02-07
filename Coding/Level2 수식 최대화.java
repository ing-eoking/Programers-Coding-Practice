import java.util.Arrays;
class Solution {
    public long spt(int n, String it, String exp){
        if(n>2) return Long.parseLong(exp);
        char tt = it.charAt(n);
        String[] arr = exp.split("\\"+Character.toString(tt));
        long temp = 0;
        if(tt == '*') temp = 1;
        if(tt == '-') temp = spt(n+1,it,arr[0])*2;
        for(int i = 0; i< arr.length; i++){
            if(tt == '*'){
                temp = temp*spt(n+1,it,arr[i]);
            }
            else if(tt == '+'){
                temp = temp+spt(n+1,it,arr[i]);
            }
            else if(tt == '-'){
                temp = temp-spt(n+1,it,arr[i]);
            }
        }
        return temp;
    }
    public long solution(String expression) {
        long answer = 0;
        String [] it = {"-+*","+-*","-*+","+*-","*+-","*-+"};
        long temp = 0;
        for(int i = 0; i< 6; i++){
            temp = Math.abs(spt(0,it[i], expression));
            if(answer < temp) answer = temp;
        }
        
        return answer;
    }
}
