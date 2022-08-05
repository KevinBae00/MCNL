//https://www.acmicpc.net/problem/2846

#include <iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;//명령 입력 개수

    cin >> n;

    int now,pre,min,value;//입력받는 숫자, 전에 입력 받는 숫자, 첫번째 숫자, 가장 큰 오두막길
    value=0;
    for(int i=0;i<n;i++){
        pre = now;
        cin >> now;
        if(i==0)min=now;

        if(i>0&&now<=pre){
            int v=pre-min;//현재 오르막길 크기
            if(v>value)value=v;
            min=now;
        }
        else if(i==n-1&&min<now){
            int v=now-min;//현재 오르막길 크기
            if(v>value)value=v;
        }

    }

    cout << value;
}