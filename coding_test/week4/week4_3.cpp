#include <iostream>
#include <list>

using namespace std;
//창영이 나쁜놈..


int main(){
    int n;//반복 횟수
    string str;//입력한 string
    list<char> l;//출력하는 리스트
    string::iterator it;//입력 받은 값에 쓰이는 반복자
    list<char>::iterator itr;//출력하는데 쓰이는 반복자 

    cin >> n;
    for(int i=0; i<n; i++){
        l.clear();
        itr=l.begin();
        cin >> str;
        for(it=str.begin();it!=str.end();it++){
            if((*it>='a'&&*it<='z')||(*it>='A'&&*it<='Z')||(*it>='0'&&*it<='9'))
                l.insert(itr,*it);
            else if(*it=='-'){
                if(itr!=l.begin()){
                    itr=l.erase(--itr);//itr의 위치가 삭제되므로 새롭게 지정
                }
            }
            else if(*it=='<'){
                if(itr!=l.begin())
                    itr--;
            }
            else if(*it=='>'){
                if(itr!=l.end())
                itr++;
            }
        }
        for(char x : l)
            cout << x;
        cout << endl;

    }
}