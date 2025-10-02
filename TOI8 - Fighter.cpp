#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    const int mx = 5e5 + 5;
    int n,m,a[mx],dist[mx];cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>a[i];
        dist[i] = a[i];
    }
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for(int i=1;i<m+1;++i){
        dist[i] += a[0];
        pq.push({dist[i],i});
    }
    for(int i=m+1;i<n;++i){
        while(i-m > pq.top().second) pq.pop();
        dist[i] += pq.top().first;
        pq.push({dist[i],i});
    }
    cout<<dist[n-1];
}
