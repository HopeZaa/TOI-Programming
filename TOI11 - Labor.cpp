#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int mx = 1e6+1;
ll n,m;
int t[mx];
bool chk(ll mid){
    ll sum = 0;
    for(int i=0;i<m;++i){
        sum += mid / t[i];
    }
    return sum >= n;
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    cin>>m>>n;
    for(int i=0;i<m;++i) cin>>t[i];
    ll low = 1 , high = 1e18;
    while(low < high){
        ll mid = low + (high - low) / 2;
        if(chk(mid)) high = mid;
        else low = mid + 1;
    }
    cout<<low<<endl;
}
