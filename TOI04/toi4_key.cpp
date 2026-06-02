#pragma GCC optimize("02")
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int a,b;cin>>a>>b;
    string l1,l2,l3;cin>>l1>>l2>>l3;
    for(int i=0;i<a;i++){
        for(int j=b-1;j>=0;j--){
            char t[]={l1[i],l2[i],l3[j]};
            sort(t,t+3);
            l3[j] = t[1];
        }
    }
    cout<<l3;
}
