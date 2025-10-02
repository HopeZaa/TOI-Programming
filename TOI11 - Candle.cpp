#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m;
string grid[2001];
bool vi[2001][2001];
void bfs(int initi,int initj){
    queue<pair<int,int>> q;
    q.push({initi,initj});
    int ii[] = {-1,-1,-1,0,0,1,1,1} , jj[] = {-1,0,1,-1,1,-1,0,1};
    while(!q.empty()){
        auto [i,j] = q.front();
        q.pop();
        if(vi[i][j]) continue;
        if(grid[i][j] == '0') continue;
        if(i<0 or i>=n or j<0 or j>=m) continue;
        vi[i][j] = true;
        for(int k=0;k<8;++k){
            int newi = i+ii[k] , newj = j+jj[k];
            if(newi<0 or newi>=n or newj<0 or newj>=m) continue;
            if(grid[newi][newj] == '0') continue;
            if(vi[newi][newj]) continue;
            q.push({newi,newj});
        }
    }
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    cin>>n>>m;
    int cnt = 0;
    for(int i=0;i<n;++i) cin>>grid[i];
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(vi[i][j]) continue;
            if(grid[i][j] == '0') continue;
            ++cnt;
            bfs(i,j);
        }
    }
    cout<<cnt;
}
