#pragma GCC optimize("02")
#include <bits/stdc++.h>
using namespace std;
int a[18][18]={0};
bool vi[18][18] = {false};
int ii[]={1,-1,0,0},jj[]={0,0,1,-1};
int dfs(int i,int j){
    vi[i][j] = true;
    int cnt = 1;
    for(int k=0;k<4;k++){
        if(!vi[i+ii[k]][j+jj[k]] && a[i][j]==a[i+ii[k]][j+jj[k]]) cnt+=dfs(i+ii[k],j+jj[k]);
    }
    return cnt;
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;cin>>n;
    int ans = 0;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>a[i][j];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==0 || vi[i][j]) continue;
            if(a[i][j]==a[i+1][j] && a[i][j]==a[i+2][j] || a[i][j]==a[i][j+1] && a[i][j]==a[i][j+2] || a[i][j]==a[i-1][j] && a[i][j]==a[i+1][j] || a[i][j]==a[i][j-1] && a[i][j]==a[i][j+1] || a[i][j]==a[i-1][j] && a[i][j]==a[i-2][j] || a[i][j]==a[i][j-1] && a[i][j]==a[i][j-2]) continue;
            if(dfs(i,j)==3) ans++;
        }
    }
    cout<<ans;
    return 0;
}
