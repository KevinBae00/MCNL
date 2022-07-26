#include <iostream>
using namespace std;

int main(){
    int n, H, W, X;//n: 명령 입력 갯수, H: 총 층수, W: 총 호수, X:몇 번째 손님인지
    int a,b;
    cin >> n;
    for(int i=0; i< n; i++){
        cin >> H >> W >> X;
        a= (X%H)==0 ? H:X%H;//H*n층일 때 X%H 은 0이 된다.
        b=(X%H)==0 ? X/H:(X/H+1);////H*n층일 때 X/H의 값이 1 추가된다.
        if(X<1||X>H*W){//방을 초과할 때
            cout<< "no room please enter again"<<endl;
            i--;
        }
        else {
            if(b<10)
                cout <<a<<"0"<<b<<endl;
            else
                cout <<a<<b<<endl;
        }
    }
}