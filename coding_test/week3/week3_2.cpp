//https://www.acmicpc.net/problem/2217

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){

    // N개의 로프 1 ≤ N ≤ 100,000
    // 각 로프가 버틸 수 있는 최대중량 0 < max_w < 10,000
    int n,w,max_w=-1;
    vector<int> rope;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> w;
        rope.push_back(w);
    }

    sort(rope.begin(),rope.end());//로프를 크기 순서대로 나열한다.

    for(int i=0;i<n;i++){
        if(rope[i]*(n-i)>max_w)max_w=rope[i]*(n-i);
    }

    cout << max_w <<"\n";
}