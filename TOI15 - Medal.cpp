#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
typedef long long ll;
const int mx = 5e5+1;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    int sum[mx],ans = 0,n;cin>>n;
    vector<int> a(n),b(n);
    for(auto &e : a) cin>>e;
    for(auto &e : b) cin>>e;
    sort(a.rbegin(),a.rend());
    sort(b.begin(),b.end());
    for(int i=0;i<n;++i) sum[i] = a[i] + b[i];
    sort(sum,sum+n);
    for(int i=1;i<n;++i) ans+=(sum[i]-sum[i-1]);
    cout<<ans;
}
