#pragma GCC optimize("02")
#include <bits/stdc++.h>
using namespace std;

int n,grid[22][22],x,y,maxN=INT_MIN;
bool vi[21][21]={false};
int idx[2][4]={{1,-1,0,0},{0,0,1,-1}};

void dfs(int i,int j){
    maxN = max(maxN,grid[i][j]);
    vi[i][j] = true;
    for(int a=0;a<4;a++){
        int r = i+idx[0][a];
        int c = j+idx[1][a];
        if(vi[r][c]) continue;
        if(r<1 || r>n || c<1 || c>n) continue;
        if(grid[r][c]==100 || grid[i][j]>=grid[r][c]) continue;
        dfs(r,c);
    }
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin>>n>>x>>y;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>grid[i][j];
    dfs(y,x);
    cout<<maxN;
    return 0;
}
