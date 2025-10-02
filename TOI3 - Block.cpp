#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int n,m,score;
char grid[7][7];
bool vi[7][7];
void print(){
    cout<<score<<endl;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j) cout<<grid[i][j]<<' ';
        cout<<endl;
    }
}
bool chk(int a,int b){
    if(grid[a+1][b] == grid[a][b]) return true;
    if(grid[a-1][b] == grid[a][b]) return true;
    if(grid[a][b+1] == grid[a][b]) return true;
    if(grid[a][b-1] == grid[a][b]) return true;
    return false;
}
void bomb(int i,int j,char text){
    if(vi[i][j]) return;
    if(grid[i][j] != text) return;
    if(i<0 or i>=n or j<0 or j>=m) return;
    vi[i][j] = true;
    grid[i][j] = '-';
    score+=5;
    bomb(i+1,j,text);
    bomb(i-1,j,text);
    bomb(i,j+1,text);
    bomb(i,j-1,text);
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    cin>>n>>m;
    cin.ignore();
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) cin>>grid[i][j];
    int _;cin>>_;
    while(_--){
        int a,b;char text;cin>>a>>b>>text;
        if(grid[a][b] == '-' or grid[a][b] == '#' or text == 'L' and grid[a][b-1] != '-' or text == 'R' and grid[a][b+1] != '-'){
            score-=5;
            continue;
        }
        else{
            if(text == 'L') swap(grid[a][b],grid[a][b-1]) , b--;
            else swap(grid[a][b],grid[a][b+1]) , b++;
            while(grid[a+1][b] == '-') swap(grid[a][b],grid[a+1][b]) , a++;
            for(int i=n-1;i>=0;--i){
                for(int j=m-1;j>=0;--j){
                    if(grid[i][j] == '#' or grid[i][j] == '-') continue;
                    while(grid[i+1][j] == '-') swap(grid[i][j],grid[i+1][j]) , i++;
                    (grid[i][j] >= 'A' and grid[i][j] <= 'Z') ? i : --i;
                    if(chk(i,j)) bomb(i,j,grid[i][j]) , memset(vi,false,sizeof(vi)) , i = n-1 , j = m-1;
                }
            }
        }
    }
    print();
}
