#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    int n,m;cin>>n>>m;
    bool isNeg[10];
    memset(isNeg,false,sizeof(isNeg));
    for(int i=0;i<m;++i){
        int a;cin>>a;
        isNeg[a] = true;
    }
    vector<int> v(n);
    iota(v.begin(),v.end(),1);
    do{
        if(isNeg[v[0]]) continue;
        for(int i=0;i<n;++i) cout<<v[i]<<' ';
        cout<<endl;
    }while(next_permutation(v.begin(),v.end()));
}
