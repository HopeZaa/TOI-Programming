#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int n,m,ansi,ansj;
string grid[1001];
bool chk(int i,int j,string text){
    int ii[] = {-1,-1,-1,0,0,1,1,1} , jj[] = {-1,0,1,-1,1,-1,0,1};
    for(int k=0;k<8;++k){
        int newi = i+ii[k] , newj = j+jj[k] , cnt = 1;
        while(1){
            if(newi < 0 or newi >= n or newj < 0 or newj >= m) break;
            if(grid[newi][newj] == text[cnt]){
                ++cnt , newi+=ii[k] , newj+=jj[k];
                if(cnt == text.length()) return true;
            }
            else break;
        }
    }
    return false;
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>grid[i];
        for(int j=0;j<m;++j) grid[i][j] = tolower(grid[i][j]);
    }
    int q;cin>>q;
    while(q--){
        string text;cin>>text;
        bool isDone = false;
        for(int i=0;i<text.length();++i) text[i] = tolower(text[i]);
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j] == text[0]){
                    ansi = i,ansj = j;
                    if(chk(i,j,text) or text.length() == 1){
                        isDone = true;
                        break;
                    }
                }
            }
            if(isDone) break;
        }
        cout<<ansi<<' '<<ansj<<endl;
    }
}
