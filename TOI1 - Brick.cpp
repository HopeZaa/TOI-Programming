#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
typedef long long ll;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    string grid[21];
    int n,m,a[21],obj[21];cin>>n>>m;
    fill(obj,obj+m,n);
    for(int i=0;i<n;++i) cin>>grid[i];
    for(int i=0;i<m;++i) cin>>a[i];
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(grid[j][i] == 'O' and obj[i] == n) obj[i] = j;
        }
    }
    for(int i=0;i<m;++i){
        if(a[i] == 0) continue;
        for(int j=obj[i]-1;j>max(obj[i]-1-a[i],-1);--j) grid[j][i] = '#';
    }
    for(int i=0;i<n;++i) cout<<grid[i]<<endl;
}
