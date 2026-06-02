#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
using pii = pair<int,int>;
using tiii = tuple<int,int,int>;
int n, m, q, sum, par[3001];
int find(int a){
    return par[a] = (a == par[a]) ? a : find(par[a]);
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;++i){
        par[i] = i;
    }
    priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
    for(int i=0;i<m;++i){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(d == 1 and find(a) != find(b)){
            par[find(a)] = par[find(b)];
        }
        pq.emplace(c, a, b);
    }
    cin >> q;
    vector<pii> v;
    for(int i=0;i<q;++i){
        int a, b;
        cin >> a >> b;
        v.emplace_back(b, a);
    }
    sort(v.begin(), v.end());
    while(!pq.empty()){
        auto [c,a,b] = pq.top();
        pq.pop();
        if(find(a) != find(b)){
            for(auto [y,x] : v){
                if(c <= x){
                    sum += y;
                    par[find(a)] = par[find(b)];
                    break;
                }
            }
        }
    }
    cout << sum;
}
