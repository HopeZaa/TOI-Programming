#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
typedef long long ll;
const int mx = 2e5+1;
int par[mx];
int find(int a){
    return par[a] = (a == par[a]) ? a : find(par[a]);
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    int n,m;cin>>n>>m;
    ll cnt = n,sum = 0;
    for(int i=1;i<=n;++i) par[i] = i;
    vector<tuple<int,int,int>> v;
    while(m--){
        int a,b,c;cin>>a>>b>>c;
        v.push_back({c-1,a,b});
    }
    sort(v.rbegin(),v.rend());
    for(auto [c,a,b] : v){
        if(find(a) == find(b)) continue;
        par[find(a)] = find(b);
        sum+=c;
        if(cnt == 1) break;
        --cnt;
    }
    cout<<sum;
}
