#pragma GCC optimize("02")
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m,maxN=INT_MIN;cin>>n>>m;
    unsigned int a[30001];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        int mx = a[i]+m;
        int upp = upper_bound(a+1,a+n,mx)-a;
        maxN = max(maxN,upp-i-1);
    }
    cout<<maxN;
}
