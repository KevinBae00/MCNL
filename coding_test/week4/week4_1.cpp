#include <iostream>
using namespace std;
#include <stack>
#include <string>

// push X: 정수 X를 스택에 넣는 연산이다.
// pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
// size: 스택에 들어있는 정수의 개수를 출력한다.
// empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
// top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.


int main(){
    int n,x;
    stack<int> s;
    string str;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> str;
        if(str=="push"){
            cin >> x;
            s.push(x);
        }
        else if(str=="pop"){
            if(s.empty()){
                cout << -1<<endl;
            }
            else{
                cout << s.top()<<endl;
                s.pop();
            }
        }
        else if(str=="size"){
            cout<<s.size()<<endl;
        }
        else if(str=="empty"){
            if(s.empty())
                cout<<"1"<<endl;
            else
                cout<<"0"<<endl;
        }
        else if(str=="top"){
            if(s.empty()){
                cout << -1<<endl;
            }
            else{
                cout << s.top()<<endl;
            }
        }
    }
}