#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
typedef long long ll;
using pll = pair<ll,ll>;
int cmp(pll a,pll b){
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    int n;cin>>n;
    vector<pair<ll,ll>> v;
    for(int i=0;i<n;++i){
        int a,b;cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(),cmp);
    int now = INT_MIN;
    for(auto [a,b] : v){
        if(now <= b){
            cout<<a<<' '<<b<<endl;
            now = b;
        }
    }
}
