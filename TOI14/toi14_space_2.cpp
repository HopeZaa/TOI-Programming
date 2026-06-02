#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int mx = 1e4+4;
int m,n,u,d,l,r,sq,dia,tri;
bitset<2001> grid[mx];
void bfs(int initi,int initj,bool isSq){
    queue<pair<int,int>> q;
    q.push({initi,initj});
    while(!q.empty()){
        auto [i,j] = q.front();
        q.pop();
        if(i<0 or i>=n or j<0 or j>=m) continue;
        if(grid[i][j] == false) continue;
        grid[i][j] = false;
        l = min(l,j) , r = max(r,j) , u = min(u,i) , d = max(d,i);
        q.push({i+1,j});
        q.push({i-1,j});
        q.push({i,j+1});
        q.push({i,j-1});
    }
    if(!isSq){
        if(r-l == d-u) ++dia;
        else ++tri;
    }
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    cin>>m>>n;
    for(int i=0;i<n;++i){
        string text;cin>>text;
        for(int j=0;j<m;++j) grid[i][j] = (text[j] == '0' ? false : true);
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(grid[i][j] == false) continue;
            l = 1e9 , r = -1e9 , u = 1e9 , d = -1e9;
            if(grid[i+1][j] == true and grid[i][j+1] == true){ //isSq
                ++sq;
                bfs(i,j,1);
            }
            else bfs(i,j,0);
        }
    }
    cout<<sq<<' '<<dia<<' '<<tri;
}
