/*https://www.acmicpc.net/problem/11650*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first){
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
    vector<pair<int,int>> v;
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