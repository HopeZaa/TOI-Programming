#pragma GCC optimize("02")
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int w,h,n,grid[4001]={0};cin>>w>>h>>n;
    while(n--){
        int x,a;cin>>x>>a;
        for(int i=x;i<x+a;i++) grid[i]+=50;
    }
    int cntN=0,cntL=0;
    for(int i=0;i<w;i++){
        if(grid[i]==0) cntN++;
        else if(grid[i]==50) cntL++;
    }
    cout<<cntN*h<<" "<<cntL*h;
}
