#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int m,n,temp,sq,dia,tri,u,d,l,r;
string grid[1001];
bool vi[1001][1001];
void dfs(int i,int j){
    if(i<0 or i>=n or j<0 or j>=m) return;
    if(grid[i][j] == '0') return;
    if(vi[i][j]) return;
    vi[i][j] = true;
    ++temp;
    u = min(u,i) , d = max(d,i) , l = min(l,j) , r = max(r,j);
    dfs(i+1,j);
    dfs(i-1,j);
    dfs(i,j+1);
    dfs(i,j-1);
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    cin>>m>>n;
    for(int i=0;i<n;++i) cin>>grid[i];
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(grid[i][j] == '0') continue;
            if(vi[i][j]) continue;
            temp = 0;
            u = 1e9 , d = -1e9 , l = 1e9 , r = -1e9;
            dfs(i,j);
            if(grid[u][l] == '1' and grid[u][r] == '1' and grid[d][l] == '1' and grid[d][r] == '1') ++sq;
            else if(grid[d][l] == '1' and grid[d][r] == '1' or grid[u][l] == '1' and grid[u][r] == '1' or grid[u][l] == '1' and grid[d][l] == '1' or grid[u][r] == '1' and grid[d][r] == '1') ++tri;
            else ++dia;
        }
    }
    cout<<sq<<' '<<dia<<' '<<tri;
}
