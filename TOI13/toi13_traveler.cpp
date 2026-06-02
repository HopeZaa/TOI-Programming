#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
using pii = pair<ll, ll>;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    vector<pii> g[n + 1];
    vector<ll> distx(n + 1, LLONG_MAX), disty(n + 1, LLONG_MAX);
    distx[a] = 0;
    for(int i=0;i<m;++i){
        int x, y, z;
        cin >> x >> y >> z;
        g[x].emplace_back(y, z);
        g[y].emplace_back(x, z);
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, a);
    while(!pq.empty()){
        auto [_,u] = pq.top();
        pq.pop();
        for(auto [v,w] : g[u]){
            if(distx[v] > distx[u] + w){
                distx[v] = distx[u] + w;
                pq.emplace(distx[v], v);
            }
        }
    }
    if(distx[b] <= c){
        cout << b << ' ' << distx[b] << ' ' << 0;
        return 0;
    }
    disty[b] = 0;
    pq.emplace(0, b);
    while(!pq.empty()){
        auto [_,u] = pq.top();
        pq.pop();
        for(auto [v,w] : g[u]){
            if(disty[v] > disty[u] + w){
                disty[v] = disty[u] + w;
                pq.emplace(disty[v], v);
            }
        }
    }
    ll node = LLONG_MAX, distance = INT_MAX;
    for(int i=0;i<=n;++i){
        if(distx[i] <= c and (disty[i] < distance or (disty[i] == distance and i < node))){
            node = i;
            distance = disty[i];
        }
    }
    cout << node << ' ' << distx[node] << ' ' << distance;
}
