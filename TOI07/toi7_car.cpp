#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int m,n,t,a[101];
char grid[101][41];
void dfs(int i,int j,int cnt){
    if(i == t){
        for(int i=0;i<cnt;++i) cout<<a[i]<<endl;
        exit(0);
    }
    if(j<1 or j>=m+1) return;
    if(grid[i+1][j-1] == '0') a[cnt] = 1 , dfs(i+1,j-1,cnt+1);
    if(grid[i+1][j+1] == '0') a[cnt] = 2 , dfs(i+1,j+1,cnt+1);
    if(grid[i+1][j] == '0') a[cnt] = 3 , dfs(i+1,j,cnt+1);
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    cin>>m>>n>>t;
    for(int i=1;i<=t;++i) for(int j=1;j<=m;++j) cin>>grid[i][j];
    dfs(0,n,0);
}
