/*https://school.programmers.co.kr/learn/courses/30/lessons/12914*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
/*다만 왜 파보니치 수열로 풀어야 하느냐
가정 n-1개의 가능성에다가 나머지 하나가 낄 가능성 n-2의 가능성을 더해서 n으로 할 수 있는 가능성을 만든다(?)

*/
long long solution(int n) {
    long long answer = 0;
    if(n==1) return answer=1;
    else if(n==2) return answer=2;
    else return answer=solution(n-1)+solution(n-2);
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",solution(n));
}