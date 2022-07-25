#include <iostream>
using namespace std;

int main(){
    int n, H, W, X;//n: 명령 입력 갯수, H: 총 층수, W: 총 호수, X:몇 번째 손님인지
    int a,b;
    cin >> n;
    for(int i=0; i< n; i++){
        cin >> H >> W >> X;
        a=X%H;
        b=X/H+1;
        if(X<1||X>H*W){//방을 초과할 때
            cout<< "no room please enter again"<<endl;
            i--;
            continue;
        }
        if(b<10)
            cout <<a<<"0"<<b<<endl;
        else
            cout <<a<<b<<endl;
    }
}