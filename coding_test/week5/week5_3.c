/*https://school.programmers.co.kr/learn/courses/30/lessons/12914*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//아직 못품
long long solution(int n) {
    long long answer = 0;
    long long o=1;
    for(int i=0;i<n;i++){
        o=1;
        for(int j=0; j<i; j++){
            o*=(n-j);
            o/=(j+1);
        }
    }
    return answer;
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",solution(n));
}