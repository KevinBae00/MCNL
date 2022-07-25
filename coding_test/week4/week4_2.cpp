#include <iostream>
using namespace std;

int main(){
    int n, H, W, X;
    int a,b;
    cin >> n;
    for(int i=0; i< n; i++){
        cin >> H >> W >> X;
        a=X%H;
        b=X/H+1;
        if(X<1||X>H*W){
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