#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int mx = 2e5 + 5;
int n, m, par[mx], a, b, c, compo;
long long ans;
vector<tuple<int, int, int>> v;
int find(int a){
    return par[a] = (a == par[a]) ? a : find(par[a]);
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    cin >> n >> m;
    compo = n;
    iota(par + 1, par + n + 1, 1);
    for(int i=0;i<m;++i){
        cin >> a >> b >> c;
        v.emplace_back(c - 1, a, b);
    }
    sort(v.rbegin(), v.rend());
    for(auto [c, a, b] : v){
        if(find(a) != find(b)){
            par[find(a)] = find(b);
            ans += (long long)c;
            --compo;
        }
        if(compo == 1){
            break;
        }
    }
    cout << ans;
}
