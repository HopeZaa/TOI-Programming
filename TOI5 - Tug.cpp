#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    int n;cin>>n;
    vector<int> a(n) , b(n);
    for(auto &e : a) cin>>e;
    for(auto &e : b) cin>>e;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int sum = 0;
    for(int i=0;i<n;++i) sum += abs(a[i] - b[i]);
    cout<<sum;
}
