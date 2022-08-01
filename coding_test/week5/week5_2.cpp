/*https://www.acmicpc.net/problem/11650*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){//sort하는 규칙
    if(a.first == b.first){//first는 첫번째  int를 말함
        return a.second<b.second;
    }else{
        return a.first<b.first;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,x,y;
    vector<pair<int,int>> v;//pair는 백터에 여러 값 넣을 때 쓴다.
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> x;
        cin >> y;
        v.push_back(pair<int,int>(x,y));
    }

    sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size();i++){
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }


}