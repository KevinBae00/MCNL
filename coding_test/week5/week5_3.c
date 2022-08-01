/*https://school.programmers.co.kr/learn/courses/30/lessons/12914*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int n) {
    long long answer = 0;
    long long odd=1;
    answer=1;
    if(n%2==1) odd=(n/2+1);
    while(n!=1){
        n/=2;
        answer*=2;
    }
    answer*=odd;
    return answer;
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",solution(n));
}