#pragma GCC optimize("02")
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;cin>>n;
    float sum=0;
    while(n--){
        float a,b,c,d,e;cin>>a>>b>>c>>d>>e;
        sum+=a+(b*3/4)+(c/2)+(d/4)+(e/8);
    }
    cout<<ceil(sum);
}
