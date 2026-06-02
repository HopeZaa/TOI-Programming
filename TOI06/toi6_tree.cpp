#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    for(int _=0;_<5;++_){
        vector<pair<int,int>> u,v;
        int n;cin>>n;
        int sz =  2*(n-1)/2;
        for(int i=0;i<sz;++i){
            int a,b;cin>>a>>b;
            u.push_back({min(a,b),max(a,b)});
        }
        for(int i=0;i<sz;++i){
            int a,b;cin>>a>>b;
            v.push_back({min(a,b),max(a,b)});
        }
        sort(u.begin(),u.end());
        sort(v.begin(),v.end());
        if(u == v) cout<<"Y";
        else cout<<"N";
    }
}
