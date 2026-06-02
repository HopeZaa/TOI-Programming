#include<bits/stdc++.h>
using namespace std;
int a[30][30];
int n , xx , yy , maxx;
void dfs(int y , int x){
    if(y < 1 or x < 1 or y > n or x > n){
        return;
    }
    if(a[y][x] == 100){
        return;
    }
    maxx = max(maxx, a[y][x]);
    if(a[y + 1][x] > a[y][x]){
        dfs(y + 1, x);
    }
    if(a[y - 1][x] > a[y][x]){
        dfs(y - 1, x);
    }
    if(a[y][x + 1] > a[y][x]){
        dfs(y, x + 1);
    }
    if(a[y][x - 1] > a[y][x]){
        dfs(y, x - 1);
    }
}
int main(){
    cin>>n;
    cin>>xx>>yy;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            cin>>a[i][j];
        }
    }
    maxx = a[yy][xx];
    dfs(yy, xx);
    cout<<maxx;
}
