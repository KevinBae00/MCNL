#include <string>
#include <iostream>

using namespace std;


int main(void){
    int count, answer=0;
    int alphabet[26];
    cin >> count;
    string a[count];
    for(int i=0; i<count; i++){
        cin >> a[i];
        for(int j=0; j<a[i].size();j++){
            cout << a[i].find("a");
        }
    }
}