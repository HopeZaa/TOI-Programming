#pragma GCC optimize("02")
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,dp[3001]={0},minN=255,maxN=1;cin>>n;
    while(n--){
        int l,h,r;cin>>l>>h>>r;
        minN=min(minN,l);
        maxN=max(maxN,r);
        for(int i=l;i<r;i++) dp[i]=max(dp[i],h);
    }
    for(int i=minN;i<=maxN;i++){
        if(dp[i]!=dp[i-1]) cout<<i<<" "<<dp[i]<<" ";
    }
}
