#pragma GCC optimize("02")
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    while(1){
        int Qb=1,Wb=1,Sb=0;
        int n;cin>>n;
        if(n==-1) break;
        while(n--){
            int tempWb=Wb;
            Wb+=Sb+Qb;
            Sb=tempWb;
        }
        cout<<Wb<<" "<<Wb+Qb+Sb<<endl;
    }
}
